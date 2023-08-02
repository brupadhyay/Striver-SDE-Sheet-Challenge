/**
 * TC - O(V*E)
 * SC - O(V)
*/

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dis(V, 1e8);
    
    dis[S] = 0;
    
    for(int i = 0;i<V-1;i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dis[u] != 1e8 && dis[u] + wt < dis[v]){
                dis[v] = dis[u] + wt;
            }
        }
    }
    
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        if(dis[u] != 1e8 && dis[u] + wt < dis[v]){
            return {-1};
        }
    }
    
    return dis;
}