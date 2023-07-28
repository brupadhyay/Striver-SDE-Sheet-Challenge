/**
 * Using search and traversal, if got from both return
 * TC - O(n)
 * SC - O(n) { worst case }
*/ 

TreeNode<int>* findLCA(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q){
    if(!root) return NULL;

    if(root -> data == P -> data) return root;
    if(root -> data == Q -> data) return root;

    TreeNode<int>* left = findLCA(root -> left, P, Q);
    TreeNode<int>* right = findLCA(root -> right, P, Q);

    if(left == NULL) return right;
    else if(right == NULL) return left;

    return root;
}

/**
 * Using property of BST to reduce search space
 * TC - O(H)
 * SC - O(H)
*/

TreeNode<int>* findLCA(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q){
    if(!root) return NULL;

    if(root -> data > P -> data && root -> data > Q -> data){
        return findLCA(root -> left, P, Q);
    }

    if(root -> data < P -> data && root -> data < Q -> data){
        return findLCA(root -> right, P, Q);
    }

    return root;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    return findLCA(root, P, Q);
}
