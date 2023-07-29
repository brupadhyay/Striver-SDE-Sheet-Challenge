/**
 * TC - O(n)
 * SC - O(n) { inorder array and recursive stack space }
*/

void getInorder(BinaryTreeNode<int> *root, vector<int> &inorder){
    if(!root) return;

    // left - root - right
    getInorder(root -> left, inorder);
    inorder.push_back(root -> data);
    getInorder(root -> right, inorder);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    vector<int> inorder;
    getInorder(root, inorder);

    BinaryTreeNode<int> *head = new BinaryTreeNode<int> (inorder[0]);
    BinaryTreeNode<int> *curr = head;
    for(int i = 1;i<inorder.size();i++){
        BinaryTreeNode<int> *temp = new BinaryTreeNode<int> (inorder[i]);
        curr -> right = temp;
        curr = curr -> right;
    }
    return head;
}