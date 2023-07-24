// L - N - R
void inorder(TreeNode* root, vector<int> &v){
    if(root == NULL) return;
    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);
}
// N - L - R
void preorder(TreeNode* root, vector<int> &v){
    if(root == NULL) return;
    v.push_back(root -> data);
    preorder(root -> left, v);    
    preorder(root -> right, v);
}

// L - R - N
void postorder(TreeNode* root, vector<int> &v){
    if(root == NULL) return;
    postorder(root -> left, v);    
    postorder(root -> right, v);
    v.push_back(root -> data);    
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> v;
    inorder(root, v);
    return v;
}

