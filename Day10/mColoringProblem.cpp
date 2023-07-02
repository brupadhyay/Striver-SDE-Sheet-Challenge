/*M – Coloring Problem
Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.*/

#include <iostream>
#include <vector>
using namespace std;

// * Time Complexity: O(N^M) (n raised to m) where m is colours

// * Space Complexity: O(N) { recursion stack space } + O(2E) { for adjacency list }

bool isPossible(int node, int currentColor, vector<int> adjList[], int color[]){
    for(auto adjNode: adjList[node]){
        if(color[adjNode] == currentColor) return false;
    }
    return true;
}

bool solve(int node, vector<int> adjList[], int color[], int n, int m){
    if(node == n){
        return true;
    }

    for(int c=1;c<=m;c++){
        // possible to color
        if(isPossible(node, c, adjList, color)){
            color[node] = c;
            if(solve(node + 1, adjList, color, n, m) == true) return true;
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> adjList[n];

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(mat[i][j] == 1){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int color[n];
    for(int i = 0;i<=n;i++){
        color[i] = -1;
    }

    return solve(0, adjList, color, n, m) ? "YES" : "NO";
}

int main() {
    int n = 4;
    int m = 3;
    vector<vector<int>> mat(n, vector<int> (n, 0));

    int edges;
    cin >> edges;
    for(int i = 0;i<edges;i++){
        int u,v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    cout << "is it possible to colour with at most "<< m << "vcolours? \n";
    cout << graphColoring(mat, m);
}