#include <bits/stdc++.h> 
using namespace std;

// circular array
/**
 * TC - O(N)
 * SC - O(N)
*/

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> res(n, -1);
    for(int i = 2*n-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i%n]){
            st.pop();
        }
        if(i < n && st.empty() == false){
            res[i] = st.top();
        }
        st.push(arr[i%n]);
    }
    return res;
}

int main() {
    vector<int> arr = {5,7,1,2,6,0};
    int n = arr.size();

    vector<int> ans = nextGreater(arr, n);
    cout << "the next greater array is "<< endl;
    for(auto x: ans){
        cout << x << " ";
    }

    return 0;
}