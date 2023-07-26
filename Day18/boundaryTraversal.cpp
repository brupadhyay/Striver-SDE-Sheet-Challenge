#include <bits/stdc++.h> 

/**
 * * Time Complexity: O(N)
 * Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)
 * * Space Complexity: O(N)
 * Reason: Space is needed for the recursion stack while adding leaves. 
 * In the worst case (skewed tree), space complexity can be O(N).
*/

bool isLeaf(TreeNode<int>* root){
    return (!root -> left && !root -> right);
}

void leftView(TreeNode<int>* root,  vector<int> &ans){
   if(root == NULL || (isLeaf(root))){
       return;
   } 
   ans.push_back(root -> data);
   if(root -> left) leftView(root -> left, ans);
   else leftView(root -> right, ans);
}


void rightView(TreeNode<int>* root, vector<int> &ans){
   if(root == NULL || (isLeaf(root))){
       return;
   } 
   
   if(root -> right) rightView(root -> right, ans);
   else rightView(root -> left, ans);
   ans.push_back(root -> data);
}

void leafNodes(TreeNode<int>* root, vector<int> &ans){
    if(!root) return;
    
    if(isLeaf(root)){
        ans.push_back(root -> data);
        return;
    }

    leafNodes(root -> left, ans);
    leafNodes(root -> right, ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
    // to avoid confusion
    ans.push_back(root -> data);

    // left nodes
    leftView(root -> left, ans);
    // take bottom nodes
    leafNodes(root -> left, ans);
    leafNodes(root -> right, ans);
    
    // right nodes
    rightView(root -> right, ans);

    return ans;
}