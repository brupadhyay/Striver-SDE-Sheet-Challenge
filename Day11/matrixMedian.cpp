#include <bits/stdc++.h>
using namespace std;

/*
BRUTE FORCE APPROACH - convert into linear, sort and return middle element
TC - O(N*M) + O(N*Mlog(N*M))
SC - O(N*M)
*/
int getMedian1(vector<vector<int>> &matrix)
{ 
    vector<int> linear;
    for(int i = 0;i<matrix.size();i++){
        for(int j = 0;j<matrix[i].size();j++){
            linear.push_back(matrix[i][j]);
        }
    }

    int n = matrix.size();
    int m = matrix[0].size();

    sort(linear.begin(), linear.end());
    // n*m is always odd
    return linear[(n*m)/2];
}

/*
OPTIMAL APPROACH - Using Binary Search
TC - O((NlogM)*log(max(matrix))) ~ O(N*logM) because log(maximum) is constant
SC - O(1)
*/

int countSmallerThanMid(int mid, vector<int> &row){
    int lo = 0, hi = row.size()-1;
    while(lo <= hi){
        int md = (lo+hi) >> 1;
        if(row[md] <= mid){
            lo = md + 1;
        } else {
            hi = md - 1;
        }
    }
    return lo;
}
int getMedian2(vector<vector<int>> &matrix)
{ 
    
    int low = INT_MAX, high = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();

    for(int i = 0;i<n;i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }

    while(low <= high){
        int mid = (low + high)/2;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt += countSmallerThanMid(mid, matrix[i]);
        }
        if(cnt <= (n*m)/2){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<vector<int>> matrix ={{2, 6, 8},{1, 4, 7},{6, 8, 9}};
    cout << "median is: "<< getMedian2(matrix);
}