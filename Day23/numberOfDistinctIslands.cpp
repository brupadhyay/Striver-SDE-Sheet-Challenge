/**
 * TC - O(n x m log (n x m)) + O(n x m x 4) { log(n x m) for set }
 * SC - O(n x m) { for the visited array and set data structure takes n x m locations }
*/

class Solution {
    bool isValid(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        
        bool isSafe = row >= 0 && row < n && col >= 0 && col < m;
        
        return isSafe && !vis[row][col] && grid[row][col] == 1;
    }
    
    
    void visitIsland(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>> &currIsland){
        queue<pair<int,int>> q;
        q.push({row, col});
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int stRow = q.front().first;
            int stCol = q.front().second;
            q.pop();
            
            currIsland.push_back({
                stRow - row,
                stCol - col
            });
            
            for(int i = 0;i<4;i++){
                int nrow = stRow + dx[i];
                int ncol = stCol + dy[i];
                
                if(isValid(nrow, ncol, grid, vis)){
                    vis[nrow][ncol] = 1;
                    q.push({ nrow, ncol});
                }
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>> > st;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> currIsland;
                    visitIsland(i, j, grid, vis, currIsland);
                    st.insert(currIsland);
                }
            }
        }
        return st.size();
    }
};