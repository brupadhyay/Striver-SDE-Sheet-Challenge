// BRUTE FORCE
// sorting the array because we want 0 - 1 - 2
// Time Complexity - O(nlogn)
// SC - O(1)

#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    sort(arr, arr + n);
}

// BETTER APPROACH
// TC - O(n) + O(n)
// SC - O(1)

void sort012(int *arr, int n)
{
   int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0;i<n;i++){
        switch(arr[i]){
            case 0: cnt0++;
            break;

            case 1: cnt1++;
            break;

            default: cnt2++;
        }
    }

    int i = 0;
    while(cnt0--){
        arr[i++] = 0;
    }
    while(cnt1--){
        arr[i++] = 1;
    }
    while(cnt2--){
        arr[i++] = 2;
    }

}

/*
Optimal Approach - Using dutch national flag algorithm
This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:

arr[0….low-1] contains 0. [Extreme left part]
arr[low….mid-1] contains 1.
arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array

and arr[mid...high] contains 0/1/2 in unsorted fashion
*/


void sort012(int *arr, int n)
{
   int low = 0, mid = 0, high = n-1;
   while(mid <= high){
        switch(arr[mid]){
            case 0: swap(arr[low++], arr[mid++]);
            break;

            case 1: mid++;
            break;

            case 2: swap(arr[mid], arr[high--]);
            break;
        }
   }
      
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort012(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
