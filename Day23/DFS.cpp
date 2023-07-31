/**
 * TC - O(V + 2E)
 * SC - O(2V) { visited and adjacency list }
*/

void dfs(int node, vector<int> adjList[], int vis[], vector<int> &component){
    vis[node] = 1;
    component.push_back(node);
    
    for(auto it: adjList[node]){
        if(!vis[it]){
            dfs(it, adjList, vis, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    int vis[V] = {0};
    vector<int> adjList[V];

    for(auto it: edges){
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }

    for(int i = 0;i<V;i++){
        vector<int> component;
        if(!vis[i]){
            dfs(i, adjList, vis, component);
            ans.push_back(component);
        }        
    }
    return ans;
}