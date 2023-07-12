#include <bits/stdc++.h>
using namespace std;

/**
 * TC - O(nlogn) { for each element we put the 
 * frequency of element in map (logn) for storing} + O(nlogn) { pushing in max heap }
 *  + O(k) { for storing answer }
 * SC - O(n) { for map } + O(k) { for storing the answer } ~ O(n)
*/
/* always tell that we are using it to store the answer not to solve the problem */

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> mpp;
    for(int i = 0;i<nums.size();i++){
        mpp[nums[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto it: mpp){
        pq.push({it.second, it.first});
    }

    vector<int> ans;
    for(int i = 0;i<k;i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}