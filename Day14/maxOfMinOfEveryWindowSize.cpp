#include <bits/stdc++.h> 
using namespace std;

/**
 * TC - O(n x n x k)
 * SC - O(1)
*/

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans;

    for(int k = 1;k<=n;k++){
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            int mini = INT_MAX;
            for(int j = i;j<i+k;j++){
                mini = min(mini, a[j]);
            }
            maxi = max(maxi, mini);
        }
        ans.push_back(maxi);
    }
    return ans;
}

/**
 * TC - O(n x n)
 * SC - O(k)
*/
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans;

    for(int k = 1;k<=n;k++){
        deque<int> dq;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            while(!dq.empty() && a[dq.back()] > a[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1) maxi = max(maxi, a[dq.front()]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

/**
 * TC - O(n) { courple of passes }
 * SC - O(n) { for using stack and additional arrays }
*/

vector<int> maxMinWindow(vector<int> a, int n) {
    int left[n];
    int right[n];
    for(int i = 0;i<n;i++){
        left[i] = 0;
        right[i] = n - 1;
    }

    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        
        if(!st.empty()){
            left[i] = st.top() + 1;
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }

    for(int i = n-1;i>=0;i--){
        while(!st.empty() && a[st.top()] >= a[i]){
            st.pop();
        }

        if(!st.empty()){
            right[i] = st.top() - 1;
        }
        st.push(i);
    }

    int ans[n+1];
    for(int i = 0;i<=n;i++){
        ans[i] = INT_MIN;
    }

    for(int i = 0;i<n;i++){
        int len = right[i] - left[i] + 1;

        ans[len] = max(ans[len], a[i]);
    }

    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);

    vector<int> res;
    for(int i = 1;i<=n;i++) res.push_back(ans[i]);
    return res;
}