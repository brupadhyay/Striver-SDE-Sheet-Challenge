#include <bits/stdc++.h>
using namespace std;

// print any one subsequence whose sum is k
// pattern is to return true once found

bool printSubsequence(int ind, int n, int arr[], int k, int &sum, vector<int> &ds){
    if(ind >= n){
        if(sum == k){
            for(auto it: ds){
                cout << it << " ";
            }
            return true;
        }
        return false;
    }
    
    // pick or add element to our data structure
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if(printSubsequence(ind + 1, n, arr, k, sum, ds) == true){
        return true;
    }
    // remove it 
    ds.pop_back();
    sum -= arr[ind];
    // call by not picking up the current element
    if(printSubsequence(ind + 1, n, arr, k, sum, ds) == true){
        return true;
    }

    // if both call didn't find any subsequence then return false
    return false;
}

int main(){
    int arr[] = {1,2,1};
    vector<int> ds;
    int k = 2;
    int sum = 0;
    printSubsequence(0, 3, arr, k, sum, ds);
}