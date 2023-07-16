#include <climits>
#include <bits/stdc++.h>
using namespace std;

/**
 * TC - O(N^2)
 * SC - O(1) { we are not using any extra space for solving the problem }
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> res(n);
    for(int i = 0;i<n;i++){
        int currElement = arr[i];
        int nextSmaller = INT_MIN;
        for(int j = i + 1;j<n;j++){
            if(arr[j] < currElement){
                nextSmaller = arr[j];
                break;
            }
        }
        if(nextSmaller != INT_MIN){
            res[i] = nextSmaller;
        } else res[i] = -1;
    }
    return res;
}

/**
 * TC - O(N)
 * SC - O(N) { for stack used for problem solving }
*/

#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> res(n, -1);
    for(int i = n-1;i>=0;i--){
        int curr = arr[i];
        if(!st.empty()){
            while(!st.empty() && st.top() >= curr){
                st.pop();
            }
        }
        
        res[i] = st.empty() ? -1 : st.top();
        
        st.push(curr);
    }
    return res;
}
