#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * BRUTE FORCE
 * TC - O(nlogn)
 * SC - O(1)
*/

int kthLargest(vector<int>& arr, int size, int k)
{
	sort(arr.begin(), arr.end());
	return arr[size - k];
}

/**
 * OPTIMAL SOLUTION
 * Using priority queue - min heap
 * TC - O(n*logk)
 * SC - O(k)
*/

int kthLargest(vector<int>& nums, int size, int k) {
    priority_queue<int, vector<int>, greater<int>> minpq;
    
    for(int i=0;i<nums.size();i++){
        if(minpq.size()<k){
            minpq.push(nums[i]);
        }else {
            if(minpq.top() < nums[i]){
                minpq.pop();
                minpq.push(nums[i]);
            }
        }
    }
    return minpq.top();
}

int main(){
    vector<int> arr = {2,1,5,6,3,8};
    cout << "kthe largest element is "<< kthLargest(arr, 6, 3);
    return 0;
}