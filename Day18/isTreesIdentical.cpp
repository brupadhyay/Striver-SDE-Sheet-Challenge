#include <bits/stdc++.h>

/*
Time Complexity: O(N).

Reason: We are doing a tree traversal.

Space Complexity: O(N)

Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).

*/

bool recur(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2) {

  // base case
  if (!root1 && !root2)
    return true;
  if (!root1 || !root2)
    return false;
  

    if(root1 -> data == root2 -> data){
        bool left =  recur(root1->left, root2->left);
        bool right = recur(root1->right, root2->right);
        return left && right;
    } return false;
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    return recur(root1, root2);
}