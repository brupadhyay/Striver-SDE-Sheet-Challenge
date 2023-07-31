/**
 * TC - O(n x m x 4)
 * SC - O(n x m) { visited array }
*/

class Solution {
    bool isLand(int r, int c, vector<vector<char>>& grid){
        return (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1');
    }

    void floodFill(int row, int col, vector<vector<char>>& grid, 
    vector<vector<int>> &vis){
        vis[row][col] = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(isLand(nrow, ncol, grid) && !vis[nrow][ncol]){
                floodFill(nrow, ncol, grid, vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    numberOfIslands++;
                    floodFill(i, j, grid, vis);
                }
            }
        }
        return numberOfIslands;
    }
};