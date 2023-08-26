/* rotate only once
1 2 3    4 1 2
4 5 6 -> 7 5 3
7 8 9    8 9 6
*/
#include <iostream>
#include <vector>
using namespace std;


/*
TC - O(n x n) + O(n x n)
SC - O(n x n)
*/

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int startRow = 0;
    int endRow = n - 1;
    int startCol = 0;
    int endCol = m - 1;
    vector<vector<int>> rotated(n, vector<int> (n, 0));
    rotated = mat; // crucial step as we may not visit single element present in between
    while(startRow < endRow && startCol < endCol){
        // first row
        for(int i = startCol;i<endCol;i++){
            rotated[startRow][i + 1] = mat[startRow][i];
        }
        
        // last column
        for(int i = startRow+1;i<=endRow;i++){
            rotated[i][endCol] = mat[i-1][endCol];
        }
        
        // last row
        for(int i = endCol-1;i>=startCol;i--){
            rotated[endRow][i] = mat[endRow][i+1];
        }
        
        // first column
        for(int i = endRow-1;i>=startRow;i--){
            rotated[i][startCol] = mat[i+1][startCol];
        }
        // shrinking the traversal size
        endCol--;
        endRow--;
        startRow++;
        startCol++;
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            mat[i][j] = rotated[i][j];
        }
    }
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix(arr, 3, 3);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}