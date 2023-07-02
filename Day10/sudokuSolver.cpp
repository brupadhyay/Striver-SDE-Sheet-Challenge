#include <bits/stdc++.h>
using namespace std;

/*
TC - O(9^m) { where m is the no.of empty cells in the matrix }
SC - O(1) { since changes are in-place }
*/

class Solution {

    bool isValid(vector<vector<char>> &board, int row, int col, char c){
        for(int i = 0;i<9;i++){
            if(board[row][i] == c) 
                return false;
            
            if(board[i][col] == c)
                return false;
            
            if(board[3*(row/3) + i / 3][3*(col/3) + i % 3] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board){
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){   
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board) == true){
                                return true;
                            } else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};