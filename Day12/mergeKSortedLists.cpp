#include <bits/stdc++.h> 
using namespace std;

/**
 * BRUTE FORCE - put all in one array and sort
 * TC - O(n*k) + O(n*klog(n*k)) { where n is average length of arrays and k is no.of arrays }
 * SC - O(n*k)
*/

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    for(int i = 0;i<kArrays.size();i++){
        for(auto x: kArrays[i]){
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

/**
 * OPTIMAL APPROACH - using sorted property and maintaining minimum
 * TC - O(klogk) + O((n*k-k)logk)
 * SC - O(k) + O(n*k) { used for storing the answer not to solve the problem }
*/

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    // klogk
    for(int i = 0;i<k;i++){
        pq.push({kArrays[i][0], {i, 0}});
    }
    
    vector<int> ans;
    // (n*k - k)log(k) // k elements are already processed
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        int val = top.first;
        int index = top.second.first;
        int elementIndex = top.second.second;
        ans.push_back(val);

        if(elementIndex + 1 < kArrays[index].size()){
            pq.push({kArrays[index][elementIndex + 1], {index, elementIndex + 1}});
        }
    }
    return ans;
}
