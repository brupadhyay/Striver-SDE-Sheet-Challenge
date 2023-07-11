#include <iostream>
using namespace std;

/**
 * Worst Case - O(N^2) and Average/Best Case is O(NlogN)
*/

int partition(int arr[], int low, int high){
    int i = low;
    int pivot = arr[high];
    for(int j = low;j<high; j++){
        if(arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high){
    if(low <= high){
        int index = partition(arr, low, high);

        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

int main() {
    int arr[] = {1, 9, 8, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);

    cout << "Sorted array is ";
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}