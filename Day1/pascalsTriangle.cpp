/*
Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
*/

// BRUTE FORCE 
// TC - O(n x n x r) ~ O(n^3)
// SC - O(1) since we are using ans to store not doing any operation on it
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
  long long res = 1;
  for (int i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return (int)res;
}

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> ans;
    for(int row = 1;row<=n;row++){
      vector<long long int> temp;
      for(int col = 1;col<=row;col++){
        temp.push_back(nCr(row-1, col-1));
      }
      ans.push_back(temp);
    }
    return ans;
}   


// OPTIMAL APPROACH
// TC - O(n x n) ~ O(n^2)
// SC - O(1)

#include <bits/stdc++.h>

vector<long long int> generateRow(int row){
  long long int res = 1;
  vector<long long int> currRow;
  currRow.push_back(1);
  for(int col = 1;col<row;col++){
      res *= (row - col);
      res /= col;
      currRow.push_back(res);
  }
  return currRow;
}

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  for(int i = 1;i<=n;i++){
      vector<long long int> temp = generateRow(i);
      ans.push_back(temp); 
  }
  return ans; 
}

/*
row = 5
    1    4      6            4             1
col 0    1      2            3             4 
    1   4/1   4x3/1x2  4x3x2/1x2x3    4x3x2x1/1x2x3x4
*/
