/*
OPTIMAL SOLUTION - 
Go on increasing count until we find one(1) else reset counter to zero
TC - O(N)
SC - O(1)
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    int findMaxConsecutiveOnes(int *nums, int size) {
        
      int cnt = 0;
      int maxi = 0;
      for (int i = 0; i < size; i++) {
        if (nums[i] == 1) {
          cnt++;
        } else {
          cnt = 0;
        }

        maxi = max(maxi, cnt);
      }
      return maxi;
    }
};

int main() {
  int nums[] = { 1, 1, 0, 1, 1, 1 };
  int size = sizeof(nums)/ sizeof(nums[0]);
  Solution obj;
  int ans = obj.findMaxConsecutiveOnes(nums, size);
  cout << "The maximum  consecutive 1's are " << ans;
  return 0;
}