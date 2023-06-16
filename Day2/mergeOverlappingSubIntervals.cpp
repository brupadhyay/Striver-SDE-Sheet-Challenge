// BRUTE FORCE
/*
TC - O(nlogn) + O(2*n)
SC - O(n) to store the merged intervals
*/
#include <bits/stdc++.h>
using namespace std; 
/*
    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval
*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    for(int i = 0;i<n;i++){
        int lower = intervals[i][0];
        int higher = intervals[i][1];

        while(i + 1 < n && higher >= intervals[i+1][0]){
            lower = min(lower, intervals[i+1][0]);
            higher = max(higher, intervals[i+1][1]);
            i++;
        }
        ans.push_back({lower, higher});
    }
    return ans;
}

/*
OPTIMAL APPROACH
instead of traversing all along and checking greedily which interval can merge,
we can use our ans list to check if the previously visited interval is merge able to 
curr interval, and thus we update the finish point of the intervals by taking the maximum.
TC - O(nlogn) + O(n)
SC - O(n)
*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    for(int i = 0;i<n; i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}
