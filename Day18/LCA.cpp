#include <bits/stdc++.h> 
/**
 * BRUTE FORCE APPROACH
 * TC - O(n) + O(n) { for x and y path finding } 
 * + O(n*n) { in worst case to find LCA }
 * SC - O(2n) { path vectors } + O(h) { recursive stack space }
*/

void findPath(TreeNode<int>* root, int target, vector<int> &path){
    if(root == NULL){
        return;
    }

    path.push_back(root -> data);
    if(path.back() == target) return;
    findPath(root -> left, target, path);
    if(path.back() == target) return;
    findPath(root -> right, target, path);
    if(path.back() == target) return;

    if(path.back() != target) path.pop_back();
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    vector<int> pathOfX, pathOfY;
    findPath(root, x, pathOfX);
    findPath(root, y, pathOfY);
    
    int n = pathOfX.size();
    int m = pathOfY.size();
    for(int i = n-1;i>=0;i--){
        for(int j = m-1;j>=0;j--){
            if(pathOfX[i] == pathOfY[j]) return pathOfY[j];
        }
    }
    return root -> data;
}

/**
 * OPTIMUM APPROACH
 * Time complexity: O(N) where n is the number of nodes.
 * Space complexity: O(N), auxiliary space.
*/

TreeNode<int> *findLCA(TreeNode<int> *root, int x, int y){
    // base case
    if(root == NULL || root -> data == x || root -> data == y){
        return root;
    }
    TreeNode<int>* left = findLCA(root -> left, x, y);
    TreeNode<int> *right = findLCA(root -> right, x, y);

    if(left == NULL){
        return right;
    } else if(right == NULL){
        return left;
    }
    // * both left and right are not null, we found our result
    return root;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int>* ans = findLCA(root, x, y);
    return ans -> data;
}
