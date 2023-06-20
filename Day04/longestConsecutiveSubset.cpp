/*
Naive Solution - for every element do a linear search for next consecutive one
and track the maximum
TC - O(n^3)
SC - O(1)
*/

/*better approach - sort the given array and start from one index and check consecutively
if previous is same do cnt++ else cnt = 1
and calculate maximum length
TC - O(nlogn) + O(n)
SC - O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    sort(begin(arr), end(arr));
    int len = 1; // single element is also longest
    int cnt = 1;
    int prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (prev + 1 == arr[i])
        {
            cnt++;
        }
        else if (prev != arr[i])
        {
            cnt = 1;
        }
        len = max(len, cnt);
        prev = arr[i];
    }
    return len;
}

/*
Optimal Approach -
run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet. Using this we can calculate the length of the longest consecutive subsequence.
find or count - set then O(logN) unordered_set then O(1)
TC - O(N) + O(2*N) { assuming hashet takes O(1) for search }
SC - O(N)
*/
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    unordered_set<int> hashset;
    for (int i = 0; i < n; i++)
    {
        hashset.insert(arr[i]);
    }

    int longestSeq = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        // checking if it's a start of sequence
        // meaning x-1 is not present
        if (hashset.find(curr - 1) == hashset.end())
        {
            int streak = 1;

            while (hashset.count(curr + 1))
            {
                streak += 1;
                curr += 1;
            }
            longestSeq = max(longestSeq, streak);
        }
    }
    return longestSeq;
}

int main()
{
    vector<int> arr{100, 200, 1, 2, 3, 4};
    int len = lengthOfLongestConsecutiveSequence(arr, arr.size());
    cout << "The longest consecutive sequence is " << len << endl;
}