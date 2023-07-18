#include <bits/stdc++.h> 
using namespace std;

class StockSpanner {
    stack<pair<int,int>> st;
    int ind;
public:
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int prev_greater = st.empty() ? -1 : st.top().second;
        st.push({price, ind});
        return ind - prev_greater;
    }
};