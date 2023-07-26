/** find maximum distance between end nodes
 * TC - O(N) { n is no.of nodes }
 * SC - O(h) { where h is height of binary tree }
*/

int findDiameter(TreeNode<int> *root, int &maxi){
    if(root == NULL){
        return 0;
    }
    int left = findDiameter(root -> left, maxi);
    int right = findDiameter(root -> right, maxi);
    maxi = max(maxi, left + right); // diameter between end nodes
    return max(left, right) + 1; // height of current node
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi = 0;
    findDiameter(root, maxi);
    return maxi;
}