/*Solution 1 - linearly check for safe position
TC - exponential (N!*N)*/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
    vector<vector<string>> ans;

    void addUtil(vector<vector<string>> &chessBoard, int n){
        vector<string> str;
        for(vector<string> v: chessBoard){
            
            string s;
            for(int i=0; i<v.size(); i++){
                s += v[i];
            }
            str.push_back(s);
        }
        ans.push_back(str);
    }

    bool safeToPlace(int row, int col, vector<vector<string>> &chessBoard, int n){
        int r = row, c = col;

        //check for left side in that row
        while(c>=0){
            if(chessBoard[r][c] == "Q"){
                return false;
            }
            c--;
        }

        //check for leftUpper Diagonal
        r = row, c = col;
        while(r>=0 && c>=0){
            if(chessBoard[r][c] == "Q"){
                return false;
            }
            r--; c--;
        }

        //check for downLeft Diagonal
        r = row, c = col;
        while(r<n && c>=0){
            if(chessBoard[r][c] == "Q"){
                return false;
            }
            r++; c--;
        }
        return true; //if here then no conflict to attack
    }

    void solveUtil(int col, vector<vector<string>> &chessBoard, int n){
        //base case
        if(col == n){
            addUtil(chessBoard, n);
            return;
        }

        //processing first column
        for(int row=0; row<n; row++){
            if(safeToPlace(row, col, chessBoard, n)){
                //place the queen
                chessBoard[row][col] = "Q";
                //recursion call
                solveUtil(col+1, chessBoard, n);
                //backtracking
                chessBoard[row][col] = ".";
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> chessBoard(n, vector<string>(n,"."));
        solveUtil(0,chessBoard,n);

        return ans;
    }
};

/*
Solution 2: optimising on safe positions check by using hashing
TC - O(N!*N)
SC - O(N*N)*/

class Solution2 {
    map<int,bool> mppRow;
    map<int,bool> leftUpperDiagonal;
    map<int,bool> leftDownDiagonal;
public:
    bool isSafeToPlace(int row, int col){
        if(mppRow[row] || leftUpperDiagonal[row - col] || leftDownDiagonal[row + col]){
            return false;
        }

        return true;
    }

    void addUtil(vector<vector<char>> &temp, vector<vector<string>> &ans){
        vector<string> possibleAnswer;
        for(vector<char> c: temp){
            string str = "";
            for(char ch: c){
                str = str + ch;
            }
            possibleAnswer.push_back(str);
        }
        ans.push_back(possibleAnswer);
    }

    void helper(int c, int n, vector<vector<char>> &temp, vector<vector<string>> &ans){
        if(c >= n){
            addUtil(temp, ans);
            return;
        }

        for(int r = 0;r<n;r++){
            if(isSafeToPlace(r, c)){
                mppRow[r] = true;
                leftUpperDiagonal[r - c] = true;
                leftDownDiagonal[r+c] = true;
                temp[r][c] = 'Q';
                helper(c + 1, n, temp, ans);
                mppRow[r] = false;
                leftUpperDiagonal[r - c] = false;
                leftDownDiagonal[r+c] = false;
                temp[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> temp(n, vector<char> (n, '.'));
        helper(0, n, temp, ans);
        return ans;
    }
};


int main() {
    Solution2 obj;
    int n = 4;
    vector<vector<string>> ans = obj.solveNQueens(n);

    cout << "The configurations are\n";
    for(int i = 0;i<ans.size();i++){
        vector<string> s = ans[i];
        cout <<"config " << i+1 << "\n";
        for(string str: s){
            cout << str << "\n";
        }
        cout << "\n";
    }
    return 0;
}