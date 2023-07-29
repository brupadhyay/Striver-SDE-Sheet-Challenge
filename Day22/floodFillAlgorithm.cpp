#include <queue>

/**
 * Using breadth-first-search
 * TC - O(n x m x 4)
 * SC - O(n x m) { visited array } + O(n x m) { queue data structure }
*/

bool isAdjacent(int x, int y, int badColor, vector<vector<int>> &vis, vector<vector<int>> &image, int n, int m ){
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && image[x][y] == badColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y,
 int newColor)
{
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> vis(n, vector<int> (m, 0));
    vector<vector<int>> copy = image;

    queue<pair<int,int>> q;
    vis[x][y] = 1;
    copy[x][y] = newColor;
    q.push({x, y});
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();

        for(int i = 0;i<4;i++){
            int newx = node.first + dx[i];
            int newy = node.second + dy[i];

            if(isAdjacent(newx, newy, image[x][y], vis, image, n, m)){
                vis[newx][newy] = 1;
                copy[newx][newy] = newColor;
                q.push({newx, newy});
            }
        }
    }
    return copy;
}