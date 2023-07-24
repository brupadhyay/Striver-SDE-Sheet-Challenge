#include <bits/stdc++.h> 
// * Time Complexity: O(N)
// * Space Complexity: O(N)

vector<int> bottomView(BinaryTreeNode<int> * root){
    if(root == NULL) return {};
    map<int, int> distanceNodeMap;
    vector<int> view;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front().first;
        int dist = q.front().second;
        q.pop();

        distanceNodeMap[dist] = front -> data;
        if(front -> left){
            q.push({front -> left, dist - 1});
        }
        if(front -> right){
            q.push({front -> right, dist + 1});
        }
    }
    for(auto it = distanceNodeMap.begin(); it != distanceNodeMap.end(); it++){
        view.push_back(it -> second);
    }
    return view;
}
