/*
BRUTE FORCE
- check all possible pairs and find inversion
TC - O(n^2)
SC - O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

long long getInversions(long long *arr, int n){
   long long cnt = 0;
   for(int i = 0;i<n-1;i++){
       for(int j = i+1;j<n;j++){
           if(arr[i] > arr[j]) cnt++;
       }
   }
   return cnt;
}


/*
OPTIMAL APPROACH
-- divide and conquer
TC - O(nlogn)
SC - O(n)
*/

int merge(long long *arr, int low, int mid, int high){
    int left = low;
    int right = mid + 1;
    vector<long long> temp;
    int cnt = 0;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
            cnt += (mid - left + 1);
        }
    }

    while(left <= mid){
        temp.push_back(arr[left++]);
    } 
    while(right <= high){
        temp.push_back(arr[right++]);
    }

    for(int i = low;i<=high;i++){
        arr[i] = temp[i - low];
    }
    return cnt;
}

long long mergeSort(long long *arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}

long long getInversions(long long *arr, int n){
   return mergeSort(arr, 0, n-1);
}

int main() {
    long long arr[] = {5, 4, 3, 2, 1};

    cout << "Inversions are "<< getInversions(arr, 5) << endl;

    return 0;
}