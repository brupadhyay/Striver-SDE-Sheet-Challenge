#include <bits/stdc++.h>
using namespace std;

// print number of subsequence whose sum is k
// pattern is to count from left and right

int printSubsequence(int ind, int n, int arr[], int k, int &sum){
    if(ind >= n){
        if(sum == k) return 1;
        return 0;
    }
    // add element to sum
    sum += arr[ind];
    int left = printSubsequence(ind + 1, n, arr, k, sum);
    sum -= arr[ind]; // remove from sum
    int right = printSubsequence(ind + 1, n, arr, k, sum);
    return left + right;
}

int main(){
    int arr[] = {1,2,1};
    int k = 2;
    int sum = 0;
    cout << printSubsequence(0, 3, arr, k, sum);
}