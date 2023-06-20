/*Three Types - 1. pairs
                2. pairs index
                3. all pairs contributing to target
*/

/*
BRUTE FORCE - generate all pairs and check
TC - O(n^2)
SC - O(1)
*/

/*
Better approach - using a hashmap to check if target-nums[i] is present
TC - O(nlogn) - ordered map if unordered then explain
SC - O(n)
If all possible pairs then store frequency of each element and if (target-nums[i]) found,
then generate frequency times pairs
*/

/*
Optimal Approach - sorting and checking pair sum(two pointers)
TC - O(nlogn) + O(n)
SC - O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> twoSum(int n, vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return {arr[left], arr[right]};
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return {-1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    pair<int, int> ans = twoSum(n, arr, target);
    cout << "the pair is " << ans.first << " " << ans.second << endl;
    return 0;
}