/**
 * TC - O(n x m x 4)
 * SC - O(n x m)
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) break;

            for(int i = 0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol < m && nrow < n && ncol >= 0){
                    int curr = max(dis, abs(heights[nrow][ncol] - heights[row][col]));
                    if(curr < dist[nrow][ncol]){
                        dist[nrow][ncol] = curr;
                        pq.push({ curr, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};