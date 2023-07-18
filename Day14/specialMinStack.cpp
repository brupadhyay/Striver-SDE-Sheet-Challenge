#include <bits/stdc++.h> 
using namespace std;

/**
 * using pairs to store and maintain the minimum
 * TC - O(1)
 * SC - O(2N)
*/

class MinStack {
    stack<pair<int,int>> st;
public:    
    void push(int val) {
        int mini;
        if(st.empty()){
            mini = val;
        } else {
            mini = min(st.top().second, val);
        }
        st.push({val, mini});
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return st.top().second;  
    }
};


/**
 * using O(N) space
 * TC - O(1)
 * SC - O(N) { stack space }
*/

class MinStack {
    stack<long long> st;
    long long mini;
    public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        } else {
            if(val < mini){
                st.push(2*1LL*val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long top = st.top();
        if(top < mini){
            mini = 2*mini - top;
        } 
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        long long top = st.top();
        if(top < mini){
            return mini;
        }
        return top;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};

