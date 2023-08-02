/**
 * TC - O(ElogV) + O(V) { for getting path }
 * SC - O(E) { for PQ } + O(V) { for distance array } + O(V) { for parent }
*/

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<int> path;
    int parent[n+1];
    int distance[n+1];
    
    vector<pair<int,int>> adjList[n+1];
    
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    
    for(int i = 1;i<=n;i++){
        parent[i] = i;
        distance[i] = (int)1e9;
    }
    distance[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adjList[node]){
            int adjacentNode = it.first;
            int edgeW = it.second;
            
            if(dis + edgeW < distance[adjacentNode]){
                parent[adjacentNode] = node;
                distance[adjacentNode] = dis + edgeW;
                pq.push({ dis + edgeW, adjacentNode });
            }
        }
    }
    
    if(distance[n] == (int)1e9) return {-1};
    // O(V)
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}