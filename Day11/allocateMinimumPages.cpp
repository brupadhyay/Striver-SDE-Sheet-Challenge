#include <bits/stdc++.h>
using namespace std;

/**
 * Approach - using binary search on answer
 * TC - O(NlogN) 
 * { for every search we try to allocate the books, along with BS taking logN }
 * SC - O(1)
 */

bool isPossible(long long mid, int n, vector<int> time)
{
    int days = 1;
    long long currLoad = 0;
    for (int i = 0; i < time.size(); i++)
    {

        // ? if curr day load is greater than our minimal
        // * we break here, eg 3 students, arr=[9,3,1] -> 9 > 7 (mid)
        if (time[i] > mid)
            return false;

        if (currLoad + time[i] <= mid)
        {
            currLoad += time[i];
        }
        else
        {
            days++;
            currLoad = time[i];
        }
    }
    return days <= n;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long ans = 0;
    long long low, high;
    for (int i = 0; i < m; i++)
    {
        low = min(low, (long long)time[i]);
        high += time[i];
    }
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (isPossible(mid, n, time))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n = 2;
    vector<int> time {12,34,67,90};
    cout << "minimum possible allocation is "<< ayushGivesNinjatest(n, 4, time);
    return 0;
}