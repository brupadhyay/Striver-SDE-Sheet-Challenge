#include <bits/stdc++.h>
using namespace std;

// print all subsequences whose sum is k
// pattern is to keep checking sum condition to print

void printSubsequence(int ind, int n, int arr[], int k, int &sum, vector<int> &ds){
    if(ind >= n){
        if(sum == k){
            for(auto it: ds){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    
    // pick or add element to our data structure
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printSubsequence(ind + 1, n, arr, k, sum, ds);
    // remove it 
    ds.pop_back();
    sum -= arr[ind];
    // call by not picking up the current element
    printSubsequence(ind + 1, n, arr, k, sum, ds);
}

int main(){
    int arr[] = {1,2,1};
    vector<int> ds;
    int k = 2;
    int sum = 0;
    printSubsequence(0, 3, arr, k, sum, ds);
}