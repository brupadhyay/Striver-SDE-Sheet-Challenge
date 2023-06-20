/*
BRUTE FORCE - generate all pairs and check
TC - O(n^4)
SC - O(2*(no. of quadruplets))
*/

/*
Better approach - using a hashset to lookup
TC - O(n^3logm) - m - size of hashset
SC - O(2*(no. of quadruplets))
*/

/*
Optimal Approach - sorting and avoiding duplicates
TC - O(n^3)
SC - O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1, l = n - 1;

            while (k < l)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[l]);
                    sort(temp.begin(), temp.end());
                    ans.push_back(temp);
                    k++;
                    l--;

                    // avoid duplicates
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                    l--;
            }
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans)
    {
        cout << "[";
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "] ";
    }
    return 0;
}