#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * TC - O(V + 2E) { for creating edges } + O(2Elog2E) { sorting edges } + 
 * O(E*4alpha*2) { for finding MST and two operations findPar() and Union() }
 * SC - O(2V) { for size and parent } + O(E) { edges pairs } + 
 * O(V-1) { mst edges }
*/

class DisjointSet{
    vector<int> parent, size;
    
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    
    void findUnionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v){
            return;
        }
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};

class Solution
{
    bool static cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>>  b){
        return a.first < b.first;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<pair<int,int>> spanningTree(int V, vector<vector<int>> adj[])
    {
        DisjointSet ds(V);
        
        int sum = 0;
        
        vector<pair<int,pair<int,int>>> edges;
        vector<pair<int,int>> mstEdges;
        
        for(int i = 0;i<V;i++){
            for(auto it: adj[i]){
                int v = it[0];
                int w = it[1];
                edges.push_back({w, {i, v}});
            }
        }
        
        sort(edges.begin(), edges.end(), cmp);
        
        
        for(auto it: edges){
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                sum += w;
                ds.findUnionBySize(u, v);
                mstEdges.push_back({u, v});
            }
            
        }
        cout <<"MST Edge Weight Sum is " << sum << endl;
        return mstEdges;
    }
};

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
    Solution obj;

    vector<pair<int,int>> mstEdges = obj.spanningTree(V, adj);

    cout << "MST edges are ";
    for(auto it: mstEdges){
        cout << "("<< it.first << ", " << it.second <<  ")" << " ";
    }

    return 0;
}