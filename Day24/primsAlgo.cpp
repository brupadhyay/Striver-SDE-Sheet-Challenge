#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * TC - O(ElogE) { for iterating on whole pq and pop operation } + 
 * O(ElogE) { because we travel all the adjacent which can be at most E edges and logE for push }
 * SC - O(V) { visited } + O(V-1) { pairs of mst } + O(E) { for priority queue }
*/

vector<pair<int,int>> spanningTree(int V, vector<vector<int>> adj[]){
    int sum = 0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    int vis[V] = {0};
    // weight, node, parent
    pq.push({0, {0, -1}}); // take any node

    vector<pair<int,int>> mstEdges;
        
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop(); // logE
        
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        
        // if already visited then we would have got minimum edge weight
        if(vis[node]) continue;
        
        // visiting for first time means minimal then mark it as visited
        vis[node] = 1;
        sum += wt;
        if(parent != -1) mstEdges.push_back({parent, node});
        
        for(auto it: adj[node]){
            int edgeW = it[1];
            int adjNode = it[0];
            if(!vis[adjNode]){
                pq.push({ edgeW, {adjNode, node} });
            }
        }
        
    }
    cout << "the sum of edge weights forming MST is " << sum << endl;
    return mstEdges;
}

int main() {
    int V = 5;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges = {{0, 1, 2}, {0, 3, 6}, {1, 3, 8}, {1, 4, 5}, {1, 2, 3}, {4, 2, 7}};
    for(auto it: edges){
        vector<int> temp(2);
        temp[0] = it[1];
        temp[1] = it[2];

        adj[it[0]].push_back(temp);

        temp[0] = it[0];
        adj[it[1]].push_back(temp);
    }

    vector<pair<int,int>> mstEdges = spanningTree(V, adj);

    cout << "MST edges are ";
    for(auto it: mstEdges){
        cout << "("<< it.first << ", " << it.second <<  ")" << " ";
    }

    return 0;
}