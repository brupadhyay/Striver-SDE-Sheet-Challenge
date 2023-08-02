/**
 * TC - O(V+E) + O(V+E) + O(V+E) + O(V+E) 
 * first for adjacency list, second for dfs in order to sort acc to finish time
 * third for reversing adjlist, fourth for bfs in scc
 * SC - O(V+E) { adjlist } + O(2V) { stack and visited }
*/

void dfs(int node, vector<int> adjList[], int vis[], stack<int> &finish){
    vis[node] = 1;
    for(auto it: adjList[node]){
        if(!vis[it]){
            dfs(it, adjList, vis, finish);
        }
    }
    finish.push(node);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> scc;
    int vis[n] = {0};
    vector<int> adjList[n];
    // v + e
    for(auto it: edges){
        adjList[it[0]].push_back(it[1]);
    }

    stack<int> finish;
    // v + e
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            dfs(i, adjList, vis, finish);
        }
    }

    // v
    for(int i = 0;i<n;i++){
        adjList[i].clear();
        vis[i] = 0;
    }
    // v + e
    for(auto it: edges){
        adjList[it[1]].push_back(it[0]);
    }
    // v + e
    while(!finish.empty()){
        int top = finish.top();
        finish.pop();
        if(!vis[top]){
            vector<int> component;
            queue<int> q;
            q.push(top);

            vis[top] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();

                component.push_back(node);
                for(auto it: adjList[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            scc.push_back(component);
        }
    }
    return scc;

}