/**
 * Maximum XOR between 2 elements of an array
 * TC - O(N x M)
 * SC - O(1)
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                maxi = max(maxi, nums[i]^nums[j]);
            }
        }
        return maxi;
    }
};

/**
 * Using TRIE and BIT Manipulation
 * TC - O(N x 32) + O(M x 32)
 * SC - O(N x 32) { worst case }
*/

struct Node{
    Node* links[2];

    bool containsKey(int bit){
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
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(int number){
        Node* curr = root;
        for(int i = 31;i>=0;i--){
            int bit = (number >> i) & 1;
            if(!curr -> containsKey(bit)){
                curr -> put(bit, new Node());
            }
            curr = curr -> get(bit);
        }
    }

    int getMax(int num){
        Node* curr = root;
        int xr = 0;
        for(int i = 31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(curr -> containsKey(!bit)){
                // setting a bit by OR operation
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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it: nums){
            trie.insert(it);
        }

        int maxi = 0;
        for(auto it: nums){
            maxi = max(maxi, trie.getMax(it));
        }
        return maxi;

    }
};