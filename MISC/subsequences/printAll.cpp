#include <bits/stdc++.h>
using namespace std;

void printSubsequence(int ind, int n, int arr[], vector<int> &ds){
    if(ind >= n){
        for(auto it: ds){
            cout << it << " ";
        }
        if(ds.size() == 0){
            cout << "{}";
        }
        cout << endl;
        return;
    }
    
    // pick or add element to our data structure
    ds.push_back(arr[ind]);
    printSubsequence(ind + 1, n, arr, ds);
    // remove it 
    ds.pop_back();
    // call by not picking up the current element
    printSubsequence(ind + 1, n, arr, ds);
}

int main(){
    int arr[] = {3,2,1};
    vector<int> ds;
    printSubsequence(0, 3, arr, ds);
}