#include <queue>
/**Using topo-sort (BFS)
 * TC - O(V + E)
 * SC - O(V) + O(V) + O(V) { queue, indegree, ordering}
*/
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> adjList[n+1];
  
  int indegree[n+1] = {0};

  for(auto it: edges){
    adjList[it.first].push_back(it.second);
    indegree[it.second]++;
  }

  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(indegree[i] == 0) q.push(i);
  }

  vector<int> ordering;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    ordering.push_back(node);
    for(auto it: adjList[node]){
      if(--indegree[it] == 0){
        q.push(it);
      }
    }
  }

  return ordering.size() != n;
}


/**
 * Using DFS
 * TC - O(V+E) + O(V)
 * SC - O(2V) + O(V) { stack space and two arrays }
*/


bool dfs(int node, int vis[], int pathvis[], vector<int> adjList[]){
  vis[node] = 1;
  pathvis[node] = 1;

  for(auto adjacent: adjList[node]){
    if(!vis[adjacent]){
      if(dfs(adjacent, vis, pathvis, adjList) == true) return true;
    } else if(pathvis[adjacent]){
      return true;
    }
  }
  pathvis[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> adjList[n+1];
  
  int vis[n+1] = {0};
  int pathvis[n+1] = {0}; 

  for(auto it: edges){
    adjList[it.first].push_back(it.second);
  }

  for(int i = 1;i<=n;i++){
    if(!vis[i]){
      if(dfs(i, vis, pathvis, adjList) == true){
        return true;
      }
    }
  }
  

  return false;
}