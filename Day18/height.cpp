/**
 * TC - O(n)
 * SC - O(h) { in worst case it will be O(n) -> skewed tree }
*/

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    int left = maxDepth(root -> left);
    int right = maxDepth(root -> right);
    return max(left, right) + 1;
}