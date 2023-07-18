#include <bits/stdc++.h> 
using namespace std;

/**
 * Brute Force Solution - using nested loops
 * TC - O(N*K) ~ O(N^2)
 * SC - O(1)
*/

vector<int> slidingWindowMaximum(vector<int> &nums, int k)
{
    vector<int> res;
    int n = nums.size();
    for(int i = 0;i<n-k+1;i++){
        int maxi = INT_MIN;
        for(int j = i;j<i+k;j++){
            maxi = max(maxi, nums[j]);
        }
        res.push_back(maxi);
    }
    return res;
}

/**
 * Using deque data structure for maintaining decreasing order
 * we remove an element from front if it's out of bound OR
 * from back if it's smaller than or equal to incoming element
 * TC - O(N) + O(N) ~ O(N)
 * SC - O(k) { at max space the deque data structure will be requiring }
*/


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int n = nums.size();
    deque<int> dq;

    for(int i = 0;i<n;i++){
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);
        if(i >= k - 1){
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}