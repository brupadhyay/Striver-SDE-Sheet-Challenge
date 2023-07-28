/**
 * TC - O(n)
 * SC - O(1) { iterative method }
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *cur = root;
    while(cur != NULL){
        if(cur -> data == x) return true;
        if(cur -> data > x){
            cur = cur -> left;
        } else {
            cur = cur -> right;
        }
    }
    return false;
}