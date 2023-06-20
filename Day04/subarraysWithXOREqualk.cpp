/*
Brute force - all subarrays
TC - O(n^2)
SC - O(1)
*/

/*
Optimal Approach - using hashing
x ^ k = xr then x = xr^k (xor by k on both sides)
Assume, the prefix XOR of a subarray ending at index i is xr. In that subarray, we will search for another subarray ending at index i, whose XOR is equal to k. Here, we need to observe that if there exists another subarray ending at index i, with XOR k, then the prefix XOR of the rest of the subarray will be xr^k.


Now, there may exist multiple subarrays with the prefix XOR xr^k. So, the number of subarrays with XOR k that we can generate from the entire subarray ending at index i, is exactly equal to the number of subarrays with the prefix XOR xr^k, present in that subarray.

TC - O(nlogn) or O(n) depending on which map is used
SC - O(n)
*/

#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    map<int, int> mpp;
    int xr = 0;
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= arr[i];
        // single element is also subarray
        if (xr == x)
        {
            cnt++;
        }

        int prefix_XOR = xr ^ x;
        cnt += mpp[prefix_XOR];
        mpp[xr]++;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    cout << "total no of subarrays with xor equals k are " << subarraysXor(arr, 6);
}