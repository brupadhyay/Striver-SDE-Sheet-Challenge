/*
NAIVE APPROACH - linear traversal in matrix
TC - O(n*m)
SC - O(1)
*/

/*
BETTER APPROACH - using column sorted and row sorted property
TC - O(m + n)
SC - O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    // start at first row, last column
    int i = 0, j = m - 1;
    while(i < n && j >= 0){
        if(mat[i][j] == target){
            return true;
        } else if(mat[i][j] > target){
            j--;
        } else i++;
    }
    return false;
}

/*
OPTIMAL APPROACH - using binary search
TC - O(log(m*n))
SC - O(1)
*/

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m*n - 1;

    while(low <= high){
        int mid = (low + high)/2;

        int element = mat[mid/m][mid%m];

        if(element == target) return true;
        else if(element > target){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = { {1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12} };

    if(searchMatrix(mat, 8)) {
        cout << "Present";
    } else cout << "Absent";
    return 0;
}   