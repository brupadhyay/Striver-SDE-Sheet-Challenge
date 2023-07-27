#include <bits/stdc++.h> 

/**
 * TC - O(n)
 * SC - O(n) { recursive stack space, O(n) in worst case - skewed tree }
*/

void change(BinaryTreeNode<int>* root){
    if(root == NULL) return;

    int childSum = 0;
    if(root -> left){
        childSum += root -> left -> data;
    }
    if(root -> right){
        childSum += root -> right -> data;
    }

    if(childSum < root -> data){
        if(root -> left) root -> left -> data = root -> data;
        if(root -> right) root -> right -> data = root -> data;
    }
    
    change(root -> left);
    change(root -> right);

    int total = 0;
    if(root -> left) total += root -> left -> data;
    if(root -> right) total += root -> right -> data;
    if(root -> left || root -> right) root -> data = total;
}

void changeTree(BinaryTreeNode < int > * root) {
    change(root);
}  