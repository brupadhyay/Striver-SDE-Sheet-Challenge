#include <bits/stdc++.h> 

/*
Time Complexity: O(N)

Assumption: Hashmap returns the answer in constant time.

Space Complexity: O(N)

Reason: We are using an external hashmap of size ‘N’.
*/

TreeNode<int>* buildTree(vector<int> &inorder, int inStart, int inEnd,
vector<int> &preorder, int preStart, int preEnd, map<int,int> &inorderIndex){
    if(inStart > inEnd || preStart > preEnd){
        return NULL;
    }

    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    int indexOfElement = inorderIndex[root -> data];

    int subTreeSize = preStart + indexOfElement - inStart;

    root -> left = buildTree(inorder, inStart, indexOfElement-1, preorder,
    preStart + 1, subTreeSize, inorderIndex);
    root -> right = buildTree(inorder, indexOfElement + 1, inEnd, preorder,
    subTreeSize + 1, preEnd, inorderIndex);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    map<int,int> inorderIndex;
    for(int i = 0;i<inorder.size();i++){
        inorderIndex[inorder[i]] = i;
    }

    int preStart = 0, preEnd = preorder.size()-1;
    int inStart = 0, inEnd = inorder.size()-1;
    return buildTree(inorder, inStart, inEnd, preorder, preStart, preEnd, inorderIndex);
}