// N meetings in one room
// Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct meeting
{
    int start;
    int end;
    int pos;
};

/* custom comparator -  return false - if you want to swap */
bool static comp(struct meeting m1, struct meeting m2)
{
    if (m1.end != m2.end)
    {
        return m1.end < m2.end;
    }
    else
        return m1.pos < m2.pos;
}

/*
Time Complexity - O(nlogn)+O(n)+O(n)~O(nlogn)
Space Complexity - O(n)  { since we used an additional data structure for storing the start time, end time, and meeting no.}
*/

void maximumMeetings(int start[], int end[], int n)
{
    struct meeting meet[n];
    // O(n)
    for (int i = 0; i < n; ++i)
    {
        meet[i].end = end[i];
        meet[i].start = start[i];
        meet[i].pos = i + 1;
    }
    // O(nlogn)
    sort(meet, meet + n, comp);

    vector<int> ans;
    vector<pair<int, int>> meetings;
    meetings.push_back({meet[0].start, meet[0].end});
    ans.push_back(meet[0].pos);
    int limit = meet[0].end;
    // O(n)
    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
            meetings.push_back({meet[i].start, meet[i].end});
        }
    }
    cout << "The order in which the meetings will be performed is " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\nPrinting the meetings intervals: " << endl;
    for(int i = 0;i<meetings.size();i++){
        cout << "(" << meetings[i].first << "," << meetings[i].second << ") ";
    }
}

int main()
{
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
    maximumMeetings(start, end, n);
    return 0;
}