/**
 * TC - O(H)
 * SC - O(1)
*/

int floorInBST(TreeNode<int> * root, int X)
{
    TreeNode<int> *cur = root;
    int ans = 0;
    while(cur != NULL){
        if(cur -> val <= X){
            ans = max(ans, cur -> val);
        }

        if(cur -> val < X){
            cur = cur -> right;
        } else {
            cur = cur -> left;
        }
    }
    return ans;
}