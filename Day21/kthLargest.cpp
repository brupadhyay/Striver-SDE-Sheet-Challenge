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

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    vector<int> inorder;
    getInorder(root, inorder);
    int n = inorder.size();
    return k > n ? -1: inorder[n - k];
}

/**
 * TC - O(min(k,n))
 * SC - O(min(k,n))
*/


TreeNode<int> * reverseInorder(TreeNode<int>* root, int &k){
    if(!root) return NULL;
    // right root left
    TreeNode<int> * right = reverseInorder(root -> right, k);
    if(right != NULL) return right; // if right not null, meaning we found kth largest
    k--;
    if(k == 0) return root; // if current is kth largest return it
    return reverseInorder(root -> left, k); // try to get answer from left

}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    TreeNode<int> * ans = reverseInorder(root, k);
    if(ans == NULL) return -1;
    return ans -> data;
}
