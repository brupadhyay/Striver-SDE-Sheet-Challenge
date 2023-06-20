/*brute force
TC - O(n^2)
SC - O(1)
*/

#include <bits/stdc++.h>
using namespace std;
int LongestSubsetWithZeroSum(vector<int> arr)
{
    // Your code here
    int maxi = 0;
    for (int left = 0; left < arr.size(); left++)
    {
        int sum = 0;
        for (int right = left; right < arr.size(); right++)
        {
            sum += arr[right];
            if (sum == 0)
            {
                maxi = max(maxi, right - left + 1);
            }
        }
    }
    return maxi;
}

/*optimal approach -
Intuition:  Now let’s say we know that the sum of subarray(i, j) = S, and we also know that the sum of subarray(i, x) = S where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.
TC - O(n)
SC - O(1)*/

int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code here
    unordered_map<int, int> mpp;
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {1, 2, -2, 4, -4};
    cout << "The longest subset length with sum 0 is " << LongestSubsetWithZeroSum(arr) << endl;

    return 0;
}