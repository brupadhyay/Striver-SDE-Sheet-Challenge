#include <bits/stdc++.h> 

/**
 * TC - O(N*log(k)) { N is nodes and k is vertical range }
 * SC - O(N) + O(k*m) { where k is nodes in map and 
 * m is avg no. of elements in vertical level }
*/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> vertical;
    queue<pair<TreeNode<int>*,int>> q;
    map<int, vector<int>> mpp;
    if(root == NULL) return vertical;
    q.push({root, 0});
    while(!q.empty()){
        TreeNode<int> *front = q.front().first;
        int dis = q.front().second;
        q.pop();

        mpp[dis].push_back(front -> data);
        if(front -> left){
            q.push({front -> left, dis - 1});
        }
        if(front -> right){
            q.push({front -> right, dis + 1});
        }
    }

    for(auto it: mpp){
        for(int &x: it.second){
            vertical.push_back(x);
        }
    }
    return vertical;
}