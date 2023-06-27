/*Minimum number of platforms required for a railway
Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait.*/

/*BRUTE FORCE - we just need to think of whether a train can interrupt some other train timing of departure
TC - O(n^2)
SC - O(1)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// this works only when sorted
int countPlatforms1(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);
    int ans = 1; // final value
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1; // count of overlapping interval of only this   iteration
        for (int j = i + 1; j <= n - 1; j++)
        {
            if(arr[j] >= arr[i] && arr[j] <= dep[i]){
                count++;
            }
        }
        ans = max(ans, count); // updating the value
    }
    return ans;
}

/*BETTER APPROACH
- don't say in interview
 */
bool static comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    else
        return a.second < b.second;
}

int calculateMinPatforms(int at[], int dt[], int n)
{

    priority_queue<int, vector<int>, greater<int>> pq;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({at[i], dt[i]});
    }

    sort(v.begin(), v.end(), comp);

    int platforms = 1;
    pq.push(v[0].second);

    for (int i = 1; i < n; ++i)
    {
        if (v[i].first > pq.top())
        {
            pq.pop();
        }
        else
        {
            platforms++;
        }
        pq.push(v[i].second);
    }
    return platforms;
}

/*
OPTIMAL SOLUTION - sorting
- because of sorting we can keep track of train which are not departed yet so that by checking arrival time we can confirm if we need an extra platform
TC - O(2nlogn) + O(2n)
SC - O(1)
*/

int countPlatforms2(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    
    int i = 1, j = 0;
    int plat_curr = 1;
    int plat_needed = 1;
    while(i<n && j<n){
        if(at[i] <= dt[j]){
            plat_curr++;
            i++;
        } else if(at[i] > dt[j]){
            plat_curr--;
            j++;
        }
        plat_needed = max(plat_needed, plat_curr);
    }
    return plat_needed;
}

int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(dep) / sizeof(dep[0]);
    cout << "Minimum number of Platforms required " << countPlatforms2(arr, dep, n) << endl;
}