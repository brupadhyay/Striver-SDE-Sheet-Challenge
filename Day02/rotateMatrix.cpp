// BRUTE FORCE 
// TC - O(n x n) + O(n x n)
// SC - O(n x n)

#include<bits/stdc++.h>

using namespace std;


/*finding the pattern

  0 1 2       0 1 2
0 1 2 3     0 7 4 1  so (0,0) -> (0, 2), (0, 1) -> (1, 2), (0, 2) => (2, 2)
1 4 5 6 ->  1 8 5 2     (1, 0) -> (0, 1), (1, 1) -> (1, 1), (1, 2) -> (2, 1)  
2 7 8 9     2 9 6 3     (2, 0) -> (0, 0), (2, 1) -> (1, 0), (2, 2) -> (2, 0)

*/

void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            matrix[i][j] = rotated[i][j];
        }
    }
}

// OPTIMAL APPROACH
/*
Algo - 1. Transpose the matrix
       2. Reverse Each Row of the transposed matrix

TC - O(n x n)
SC - O(1)
*/

void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
        // O(n)
        reverse(matrix[i].begin(), matrix[i].end());
    }

    // or we can use reversing logic in O(n / 2) time
    /*function reverse(){
        for(int i = 0;i<n/2;i++){
            swap(arr[i], arr[n-i-1]);
        }
    }*/
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}
