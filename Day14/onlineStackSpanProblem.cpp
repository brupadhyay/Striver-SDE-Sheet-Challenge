#include <bits/stdc++.h> 
using namespace std;

/**
 * TC - O(N x N)
 * SC - O(1)
*/

vector<int> findSpans1(vector<int> &price) {
    vector<int> ans;
    int n = price.size();
    for(int i = 0;i<n;i++){
        int cnt = 0;
        for(int j = i;j>=0;j--){
            if(price[j] > price[i]) break;
            cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}

/**
 * using previous greater element concept
 * Time Complexity - O(N) { where n is the size of the input price vector  }
 * While-loop inside the for-loop: In the worst case, 
 * the while-loop can iterate through all elements of the stack 
 * (consider the case when the price vector is sorted in non-decreasing order). 
 * However, it is important to note that each element is pushed to and popped from the stack at most once. 
 * Therefore, the total number of iterations of the while-loop across the 
 * entire loop is bounded by n.
 * Space Complexity - O(N) { in the worst case we may hold up all elements 
 * index in the stack if the array is in descending order }
*/

vector<int> findSpans2(vector<int> &price) {
    vector<int> ans;
    int n = price.size();
    vector<int> prev_greater(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && price[st.top()] <= price[i]){
            st.pop();
        }
        prev_greater[i] = st.empty() ? -1 : st.top();
        st.push(i);
        ans.push_back(i - prev_greater[i]);
    }

    return ans;
}

int main(){
    vector<int> price = {4,2,3,3,7};
    vector<int> ans = findSpans2(price);
    for(auto x: ans){
        cout << x << " ";
    }

    return 0;
}