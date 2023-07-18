#include <bits/stdc++.h>
using namespace std;

/**
 * Time Complexity: O(n x m) + O(n x m x 4)    
 * Reason: Worst-case – We will be making each fresh orange rotten in the grid 
 * and for each rotten orange will check in 4 directions
 * Space Complexity: O (n x m)
 * Reason: worst-case –  If all oranges are Rotten, 
 * we will end up pushing all rotten oranges into the Queue data structure
*/

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int mintime = 0;
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int freshCnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 2){
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            } 
            if(grid[i][j] == 1){
                freshCnt++;
            }
        }
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int row = front.first.first;
        int col = front.first.second;
        int time = front.second;

        mintime = max(mintime, time);

        for(int i = 0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n
            && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                q.push({{nrow, ncol}, time + 1});
                vis[nrow][ncol] = 1;
                freshCnt--;
            }
        }
    }
    return freshCnt == 0 ? mintime : -1;
}