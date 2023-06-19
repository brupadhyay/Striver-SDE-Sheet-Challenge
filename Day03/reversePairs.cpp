/*
BRUTE FORCE - two loops and check each possible pair
TC - O(n^2)
SC - O(1)
*/

/*
OPTIMAL APPROACH - using merge sort and counting pairs separately
if we have
arr1 = 6 7 9
arr2 = 1 2 3 4
then for i = 0, 1 (arr1[0] > arr2[i]) but at i = 2 it breaks
so next time for next element in arr1 we don't start from start in arr2
instead we start where we stopped because the previously included index where forming pairs with
a number which is less than curr arr1 so it's very obvious they will form with it as well
because of the sorted property

* TC - O(2N x logN)
  Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

* SC - O(N) { temp array in merge function}
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt += right - (mid + 1);
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int reversePairs(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {4, 1, 2, 3, 1};
    cout << "Total number of reverse pairs is " << reversePairs(arr, arr.size()) << endl;
    return 0;
}