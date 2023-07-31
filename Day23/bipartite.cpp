/**
 * Using DFS
 * TC - O(V + 2E)
 * SC - O(2V) { color array } + O(V) { dfs stack space }
*/

class Solution {
    bool checkBipartite(int node, int parentColor, vector<int> &color, vector<vector<int>>& graph){
        color[node] = parentColor;

        for(auto it: graph[node]){
            if(color[it] == -1){
                if(checkBipartite(it, !parentColor, color, graph) == false){
                    return false;
                }
            } else {
                // if previously coloured and have the same colour
                if(color[it] == parentColor){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(checkBipartite(i, 0, color, graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};

/**
 * Using BFS
 * TC - O(V + 2E) V - vertices and degrees = 2E
 * SC - O(2V) { queue and color }
*/

class Solution {
    bool bfs(int node, vector<int> &color, vector<vector<int>>& graph){
        color[node] = -1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                } else {
                    if(color[it] == color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(bfs(i, color, graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};