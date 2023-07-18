#include <bits/stdc++.h>
using namespace std;
/**
 * Using naive solution - figuring out possible answer
 * TC - O(N*N)
 * SC - O(1)
*/

int largestRectangleArea(vector<int> &heights){
    int maxHeight = 0;
    int n = heights.size();

    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = i; j < n; j++)
        {
            mini = min(mini, heights[j]);
            maxHeight = max(maxHeight, mini * (j - i + 1));
        }
    }
    return maxHeight;
}

/**
 * Using left smaller and right smaller element 
 * Time Complexity: O(N) + O(N) + O(N) + O(N) ~ O(N)
 * Space Complexity: O(3N) where 3 is for the stack, 
 * left small array and a right small array
*/

int largestRectangleArea(vector<int>& heights) {
    int maxHeight = 0;
    int n = heights.size();

    stack<int> st;
    int leftsmaller[n], rightsmaller[n];
    for(int i = 0;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()){
            leftsmaller[i] = 0;
        } else {
            leftsmaller[i] = st.top() + 1;
        }

        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()){
            rightsmaller[i] = n - 1;
        } else {
            rightsmaller[i] = st.top() - 1;
        }

        st.push(i);
    }

    for(int i = 0;i<n;i++){
        maxHeight = max(maxHeight, heights[i]*(rightsmaller[i] - leftsmaller[i] + 1));
    }
    
    return maxHeight;
}

/**
 * Using single pass for figuring out right small and left small by stack
 * TC - O(N) + O(N)
 * SC - O(N)
*/

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for(int i = 0;i<=n;i++){
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
            int length = heights[st.top()];
            st.pop();

            int width;
            if(st.empty()){
                width = i;
            } else {
                width = i - st.top() - 1;
            }
            maxArea = max(maxArea, width*length);
        }
        st.push(i);
    }
    return maxArea;
}