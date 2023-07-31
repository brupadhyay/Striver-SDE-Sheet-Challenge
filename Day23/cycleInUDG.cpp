/*Time Complexity: O(V + 2E) + O(V), 
Where V = Nodes, 2E is for total degrees as we traverse all adjacent nodes. 
In the case of connected components of a graph, it will take another O(V) time.

Space Complexity: O(V) + O(V) ~ O(V), Space for adjacency list and visited array.*/

bool dfs(int node, int parent, vector<int> adjList[], int vis[]){
    vis[node] = 1;
    for(auto adjNode: adjList[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode, node, adjList, vis) == true){
                return true;
            }
        } else {
            // if already visited and not the parent 
            // means it's a cycle
            if(adjNode != parent){
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    int vis[n+1] = {0};
    vector<int> adjList[n+1];
    for(auto it: edges){
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }

    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i, -1, adjList, vis) == true){
                return "Yes";
            }
        }
    }
    return "No";
}


/*Using BFS*/
#include <queue>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    int vis[n+1] = {0};
    vector<int> adjList[n+1];
    for(auto it: edges){
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }

    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            queue<pair<int,int>> q;
            q.push({i, -1});
            vis[i] = 1;

            while(!q.empty()){
                auto u = q.front();
                q.pop();

                int node = u.first;
                int parent = u.second;
                for(auto adjacent: adjList[node]){
                    if(!vis[adjacent]){
                        vis[adjacent] = 1;
                        q.push({adjacent, node});
                    } else {
                        if(adjacent != parent){
                            return "Yes";
                        }
                    }
                }
            }
        }
    }
    return "No";
}
