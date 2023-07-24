#include <bits/stdc++.h> 

/**
 * TC - O(N)
 * SC - O(N)
*/

vector<int> getTopView(TreeNode<int> *root) {
    
    vector<int> v;
    if(root == NULL) return v;
    map<int, int> mpp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        int dist = q.front().second;
        TreeNode<int> * front = q.front().first;
        q.pop();

        if(mpp.find(dist) == mpp.end()){
            mpp[dist] = front -> val;
        }
        if(front -> left){
            q.push({front -> left, dist - 1});
        }
        if(front -> right){
            q.push({front -> right, dist + 1});
        }
    }

    for(auto it: mpp){
        v.push_back(it.second);
    }
    return v;
}