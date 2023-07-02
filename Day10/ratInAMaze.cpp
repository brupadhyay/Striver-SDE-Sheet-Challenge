
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).
*/

class Solution{
    bool isSafe(int row, int col, int n, vector<vector<int>> &vis, vector<vector<int>> &m){
      return (row >= 0 && row < n && col >= 0 && col < n && !vis[row][col] && m[row][col]);
    }
    
    void solve(int row, int col, string path, vector<vector<int> > &m, vector<vector<int> > &vis, int n, vector<string> &ans, int delrow[], int delcol[]){
      if(row == n-1 && col == n-1){
        ans.push_back(path);
        return;
      }
      
      string move = "URDL";
      for(int i = 0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(isSafe(nrow, ncol, n, vis, m)){
            vis[row][col] = 1;
            solve(nrow, ncol, path + move[i], m, vis, n, ans, delrow, delcol);
            vis[row][col] = 0;
        }
      } 
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        if(m[0][0] == 1){
            solve(0, 0, "", m, vis, n, ans, delrow, delcol);
        }
        return ans;
    }
};

    

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}