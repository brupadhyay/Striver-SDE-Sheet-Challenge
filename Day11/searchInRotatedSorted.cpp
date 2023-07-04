#include <bits/stdc++.h>
using namespace std;

/*
BRUTE FORCE - linear search algorithm
TC - O(N)
SC - O(1)
*/

int search1(int* arr, int n, int key) {
    for(int i = 0;i<n;i++){
        if(arr[i] == key) return i;
    }
    return -1;
}

/*
OPTIMAL APPROACH - using binary search and checking which part is sorted
and moving to that and checking if target is present
TC - O(logN)
SC - O(1)
*/

int search2(int* arr, int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(arr[mid] == key) return mid;
        // if the left part is sorted
        if(arr[low] <= arr[mid]){
            // if lies in left half
            if(arr[low] <= key && key <= arr[mid]){
                high = mid - 1; 
            } else { // if not present in the left half
                low = mid + 1;
            }
        } else { // right part is sorted
            if(arr[mid] <= key && key <= arr[high]){
                // element exist 
                low = mid + 1;
            } else {
                // doesn't exist
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2,3};
    cout << "key present at " << search2(arr, 8, 1);
}