

#include<iostream>
#include <vector>
using namespace std;

/*
BRUTE FORCE - by observation a water stored at a block is min(leftmax, rightmax) - block
TC - O(n^2)
SC - O(1)
*/
int trap1(vector < int > & arr) {
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

/*BETTER APPROACH - to do some precalculations to find leftmax and right max in O(1)
- use prefix and suffix array
TC - O(n) + O(n) + O(n) ~ O(n)
SC - O(2*n)
*/

int trap2(vector<int>& height) {
    int n = height.size();
    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);

    prefix[0] = height[0];
    for(int i = 1;i<n;i++){
        prefix[i] = max(height[i], prefix[i-1]);
    }

    suffix[n-1] = height[n-1];
    for(int i = n-2;i>=0;i--){
        suffix[i] = max(height[i], suffix[i+1]);
    }

    int rainTrapped = 0;
    for(int i = 0;i<n;i++){
        int boundary = min(prefix[i], suffix[i]);
        rainTrapped += boundary - height[i];
    }
    return rainTrapped;
}


/*
MOST OPTIMAL SOLUTION - two pointers
first explain logic and then intuition
TC - O(n)
SC - O(1)
*/
int trap3(vector<int>& height) {
    int n = height.size();

    int l = 0, r = n-1;
    int leftmax = 0, rightmax = 0;
    int rainTrapped = 0;
    while(l < r){
        if(height[l] <= height[r]){
            if(height[l] >= leftmax) {
                leftmax = height[l];
            }
            else rainTrapped += leftmax - height[l];

            l++;
        } else {
            if(height[r] >= rightmax) {
                rightmax = height[r];
            } 
            else rainTrapped += rightmax - height[r];

            r--;
        }
    }
    return rainTrapped;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap3(arr) << " units" << endl;
}
