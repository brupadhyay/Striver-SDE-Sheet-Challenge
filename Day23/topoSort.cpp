/**Using BFS
 * TC - O(V+E)
 * SC - O(2V) { queue and indegree }
 */

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> order;
    int indegree[V] = {0};

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        order.push_back(node);
        for (auto it : adj[node])
        {
            if (--indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return order;
}

/**Using DFS (stack)
 * TC - O(V + E) + O(V) { disconnected graph }
 * SC - O(2V) { vis and stack space }
 */

void dfs(int node, int vis[], vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;

    for (auto v : adj[node])
    {
        if (!vis[v])
        {
            dfs(v, vis, adj, st);
        }
    }
    st.push(node);
}

public:
// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> order;
    stack<int> st;
    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    while (!st.empty())
    {
        order.push_back(st.top());
        st.pop();
    }
    return order;
}