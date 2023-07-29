/**
 * Inorder OF BST is sorted
 * TC - O(N)
 * SC - O(N) + O(N) { recursive stack space and inorder array }
*/

void getInorder(TreeNode<int> *root, vector<int> &inorder){
    if(!root) return;

    getInorder(root -> left, inorder);
    inorder.push_back(root -> data);
    getInorder(root -> right, inorder);    
}

int kthSmallest(TreeNode<int> *root, int k)
{
    vector<int> inorder;
    getInorder(root, inorder);
    int n = inorder.size();
    return inorder[k-1];
}

/**
 * TC - O(min(k,N))
 * SC - O(min(k,N))
*/
TreeNode<int> * findKthSmallest(TreeNode<int> *root, int &k){
    if(!root) return NULL;

    // Left Root Right
    TreeNode<int> * left = findKthSmallest(root -> left, k);
    if(left != NULL) return left;
    k--;
    if(k == 0) return root;
    return findKthSmallest(root -> right, k);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    TreeNode<int> *ans = findKthSmallest(root, k);
    return ans -> data;
}