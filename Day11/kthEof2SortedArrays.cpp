/**
 * BRUTE FORCE - going till the kth smallest element
 * Time Complexity - O(k) { we are traversing atmost k times }
 * Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int ninjaAndLadoos1(vector<int> &row1, vector<int> &row2, int m, int n, int k) {

    int i = 0, j = 0;
    int res = -1;
    while(i < m && j < n){
        if(row1[i] <= row2[j]){
            res = row1[i++];
        } else {
            res = row2[j++];
        }
        k--;
        if(k == 0) return res;
    }

    while(i < m){
        k--;
        res = row1[i++];
        if(k == 0) return res;
    }

    while(j < n){
        res = row2[j++];
        k--;
        if(k == 0) return res;
    }
    return res;
}

/**
 * OPTIMAL SOLUTION - using binary search ( similar to median of two sorted arrays)
 * Time Complexity - O(log(min(m, n)))
 * Space Complexity - O(1)
 * Edge cases - 
 * 1. if (k < min(m, n)) then we can't take more than k elements from one array
 * 2. if (k > max(m, n)) then low can't take 0 elements it has to be min(0, k - max(m, n))
*/

#include <climits>
int ninjaAndLadoos2(vector<int> &row1, vector<int> &row2, int m, int n, int k) {

    if(m > n){
        return ninjaAndLadoos2(row2, row1, n, m, k);
    }

    int low = max(0, k - n);
    int high = min(k, m);
    while(low <= high){
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int left1 = cut1 == 0 ? INT_MIN : row1[cut1-1];
        int left2 = cut2 == 0 ? INT_MIN : row2[cut2-1];

        int right1 = cut1 == m ? INT_MAX : row1[cut1];
        int right2 = cut2 == n ? INT_MAX : row2[cut2];

        if(left1 <= right2 && left2 <= right1){
            return max(left1, left2);
        } else if(left2 > right1){
            low = cut1 + 1;
        } else {
            high = cut1 - 1;
        }
    }
    return row1[low];
}

int main() {
    vector<int> row1 = {2,3,6,7,9};
    vector<int> row2 = {1,4,8,10};
    int k = 5;
    cout<<"The element at the kth position in the final sorted array is "
    <<ninjaAndLadoos2(row1,row2,5,4,k);
    return 0;
}