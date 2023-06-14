#include <bits/stdc++.h>
using namespace std;


// BRUTE FORCE
// TC - O((n x m)x(n + m)) + O(n x m)
// SC - O(1)

void setZeros(vector<vector<int>> &mat)
{
	int n = mat.size(), m = mat[0].size();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(mat[i][j] == 0){
				for(int k = 0;k<n;k++){
					if(mat[k][j] != 0) mat[k][j] = -1;
				}
				for(int k = 0;k<m;k++){
					if(mat[i][k] != 0) mat[i][k] = -1; 
				}
			}
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(mat[i][j] == -1) mat[i][j] = 0;
		}
	}
}


// BETTER APPROACH
// TC - O(2 x (n x m))
// SC - O(n) + O(m)

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();
	int row[n] = {0};
	int col[m] = {0};

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(matrix[i][j] == 0){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(row[i] || col[j]){
				matrix[i][j] = 0;
			}
		}
	}
}

// OPTIMAL APPROACH
// TC - O(2 x (n x m))
// SC - O(1)

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();

	int col0 = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				
				if(j != 0){
					matrix[0][j] = 0;
				} else {
					col0 = 0;
				}
			}
		}
	}
	
	for(int i = 1;i<n;i++){
		for(int j = 1;j<m;j++){
			if(matrix[i][j] != 0){
				if(matrix[i][0] == 0 || matrix[0][j] == 0){
					matrix[i][j] = 0;
				}	
			}
		}
	}

	if(matrix[0][0] == 0){
		for(int i = 0;i<m;i++){
			matrix[0][i] = 0;
		}
	}

	if(col0 == 0){
		for(int i = 0;i<n;i++){
			matrix[i][0] = 0;
		}
	}
}
