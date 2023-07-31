/**
 * TC - O(V + 2E) + O(V) { for connected components }
 * SC - O(3V) { adjacent list, queue and visited array }
*/

void bfsTravel(int node, int vis[], vector<int> adjList[], vector<int> &bfsTraversal){
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        bfsTraversal.push_back(u);

        for(auto adjNode: adjList[u]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push(adjNode);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> bfsTraversal;
    vector<int> adjList[vertex];
    int vis[vertex] = {0};

    for(auto it: edges){
        adjList[it.first].push_back(it.second);
        adjList[it.second].push_back(it.first);
    }

    for(int i = 0;i<vertex;i++){
        vector<int> adjacent = adjList[i];
        sort(adjacent.begin(), adjacent.end());
        adjList[i] = adjacent;
    }

    for(int i = 0;i<vertex;++i){
        if(!vis[i]){
            bfsTravel(i, vis, adjList, bfsTraversal);
        }
    }
    return bfsTraversal;
}