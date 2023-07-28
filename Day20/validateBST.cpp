#include <bits/stdc++.h> 

/**
 * Using property - inorder of bst is sorted
 * TC - O(n) { for inorder } + O(n) { for checking sorted or not }
 * SC - O(n) { for inorder vector }
*/

void getInorder(BinaryTreeNode<int> *root, vector<int> &inorder){
    BinaryTreeNode<int> *cur = root;

    while(cur != NULL){
        if(cur -> left == NULL){
            inorder.push_back(cur -> data);
            cur = cur -> right;
        }
        else {
            BinaryTreeNode<int> *prev = cur -> left;
            while(prev -> right && prev -> right != cur){
                prev = prev -> right;
            }
            if(prev -> right == NULL){
                prev -> right = cur;
                cur = cur -> left;
            } else {
                prev -> right = NULL;
                inorder.push_back(cur -> data);
                cur = cur -> right;
            }
        }
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    vector<int> inorder;

    if(!root) return true;
    getInorder(root, inorder);
    
    for(int i = 0;i<inorder.size()-1;i++){
        if(inorder[i] > inorder[i+1]) return false;
    }
    return true;    
}

/**
 * OPTIMAL APPROACH - using property for checking range
 * TC - O(n)
 * SC - O(n) { worst case - recursive stack space - skewed binary search tree }
*/

bool validate(BinaryTreeNode<int> *root, int mini, int maxi){
    if(!root) return true;

    int curr = root -> data;
    if(curr < mini || curr > maxi){
        return false;
    }

    bool left = validate(root -> left, mini, curr);
    bool right = validate(root -> right, curr, maxi);
    
    return left && right ? true : false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    return validate(root, INT_MIN, INT_MAX);
}