#include <bits/stdc++.h>

/**
 * TC - O(n)
 * SC - O(n) { extra space for linked list }
*/

void helper(TreeNode<int> *root, TreeNode<int> *&curr){
    if(!root){
        return ;
    }
    curr -> right = new TreeNode<int> (root -> data);
    curr = curr -> right;
    helper(root -> left, curr);
    helper(root -> right, curr);
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *head = new TreeNode<int> (-1);
    TreeNode<int> *curr = head;
    if(!root) return NULL;
    helper(root, curr);
    return head -> right;
}

/**
 * Using reverse postorder traversal
 * R - L - N
 * TC - O(N)
 * SC - O(N) { skewed tree }
*/

void flatten(TreeNode<int> *root, TreeNode<int> *&prev){
    if(!root) return;
    flatten(root -> right, prev);
    flatten(root -> left, prev);

    root -> right = prev;
    root -> left = NULL;
    prev = root;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prev = NULL;
    if(!root) return NULL;
    flatten(root, prev);
    return root;
}

/**using morris preorder traversal
 * TC - O(N)
 * SC - O(1)
*/
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>* cur = root;
    if(!cur) return NULL;
    while(cur != NULL){
        if(cur -> left != NULL) {
            TreeNode<int>* prev = cur -> left;
            while(prev -> right){
                prev = prev -> right;
            }
            prev -> right = cur -> right; // thread  
            cur -> right = cur -> left;
            cur -> left = NULL;
            cur = cur -> right;                        
        }
        else {
            cur = cur -> right;
        }
    }
    return root;
}