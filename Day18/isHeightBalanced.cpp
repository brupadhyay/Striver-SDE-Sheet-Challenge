#include <bits/stdc++.h> 
/**
 * using recursion
 * TC - O(n)
 * SC - O(h) :h -> height of binary tree { worst case: O(n) } 
 * - recursive stack space
*/

pair<int,int> isBalanced(BinaryTreeNode<int> *root){
    if(root == NULL){
        return {true, 0};
    }
    pair<int,int> left = isBalanced(root -> left);
    if(!left.first){
        return {false, left.second + 1};
    }
    pair<int,int> right = isBalanced(root -> right);
    if(!right.first){
        return {false, right.second + 1};
    }
    
    bool heightFlag = abs(left.second - right.second) <= 1;
    if(!heightFlag){
        return {false, max(left.second,right.second) + 1};
    }
    return {true, max(left.second,right.second) + 1};
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    pair<int,int> ans = isBalanced(root);
    return ans.first;
}

/**
 * if strikes the mind then I'll do it!
*/
int isBalanced(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int left = isBalanced(root -> left);
    if(left == -1){
        return -1;
    }
    int right = isBalanced(root -> right);
    if(right == -1){
        return -1;
    }

    if(abs(right - left) > 1){
        return -1;
    }
    return max(left, right) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return isBalanced(root) != -1;
}