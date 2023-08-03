/**
 * BRUTE FORCE
 * TC - O(N x Q)
 * SC - O(1)
*/
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto it: queries){
            int xi = it[0];
            int mi = it[1];
            int maxi = -1;
            for(int i = 0;i<nums.size();i++){
                if(nums[i] <= mi){
                    maxi = max(maxi, xi^nums[i]);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

/**
 * Using trie and offline queries
 * TC - O(NlogN) + O(QlogQ) + O((Q+N) x 32)
 * SC - O(Q) + O(Nx32) { worst case for trie }
*/

struct Node{
    Node* links[2];

    bool contains(int bit){
        return links[bit] != NULL;
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* curr = root;
        for(int i = 31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(!curr -> contains(bit)){
                curr -> put(bit, new Node());
            }
            curr = curr -> get(bit);
        }
    }

    int findMax(int num){
        int xr = 0;
        Node* curr = root;
        for(int i = 31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(curr -> contains(!bit)){
                xr = xr | (1 << i);
                curr = curr -> get(!bit);
            } else {
                curr = curr -> get(bit);
            }
        }
        return xr;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> ans(q, -1);

        vector<pair<int,int>> offlineQueries;
        for(int i = 0;i<q;i++){
            offlineQueries.push_back({queries[i][1], i});
        }
        // QlogQ
        sort(offlineQueries.begin(), offlineQueries.end());

        // NlogN
        sort(nums.begin(), nums.end());

        Trie trie;
        int arrIndex = 0;
        // O(Q*32 + N*32)
        for(int i = 0;i<q;i++){
            int qIndex = offlineQueries[i].second;
            
            // totally bounded by N
            while(arrIndex < nums.size() && nums[arrIndex] <= offlineQueries[i].first){
                trie.insert(nums[arrIndex]);
                arrIndex++;
            }
            if(arrIndex == 0){
                ans[qIndex] = -1;
            } else {
                ans[qIndex] = trie.findMax(queries[qIndex][0]);
            }
        }
        
        return ans;
    }
};