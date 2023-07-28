/**
 * TC - O(N) + O(N)
 * SC - O(N)
*/
void getInorder(BinaryTreeNode<int> *root, vector<int> &inorder){
    BinaryTreeNode<int> *cur = root;

    while(cur != NULL){
        if(cur -> left == NULL){
            inorder.push_back(cur -> data);
            cur = cur -> right;
        }
        else {
            BinaryTreeNode<int> *prev = cur -> left;
            while(prev -> right && prev -> right != cur){
                prev = prev -> right;
            }
            if(prev -> right == NULL){
                prev -> right = cur;
                cur = cur -> left;
            } else {
                prev -> right = NULL;
                inorder.push_back(cur -> data);
                cur = cur -> right;
            }
        }
    }
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ans = {-1,-1};
    vector<int> inorder;
    getInorder(root, inorder);

    for(int i = 0;i<inorder.size();i++){
        if(inorder[i] == key){
            if(i - 1 >= 0) ans.first = inorder[i-1];
            if(i + 1 < inorder.size()) ans.second = inorder[i+1];
        }
    }
    return ans;
}
/*
Time Complexity: O(h), where h is the height of the tree. 
In the worst case as explained above we travel the whole height of the tree.
Auxiliary Space: O(1),  since no extra space has been taken.*/
void findPreSuc(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& pre, BinaryTreeNode<int>*& suc, int key)
{
    // Base case
    if (root == NULL)  return;
 
    // If key is present at root
    if (root->data == key)
    {
        // the maximum value in left subtree is predecessor
        if(root -> left != NULL){
            BinartTreeNode<int> *prev = root -> left;
            while(prev -> right){
                prev = prev -> right;
            }
            pre = prev;
        }
 
        // the minimum value in right subtree is successor
        if(root -> right != NULL){
            BinartTreeNode<int> *prev = root -> right;
            while(prev -> left){
                prev = prev -> left;
            }
            suc = prev;
        }
        return;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->data > key) {
        suc = root;
        findPreSuc(root -> left, pre, suc, key);
    }
    else // go to right subtree
    {
        pre = root;
        findPreSuc(root -> right, pre, suc, key);
    }
}
 

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ans = {-1,-1};
    BinaryTreeNode<int>* pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, key);
    if(pre) ans.first = pre -> data;
    if(suc) ans.second = suc -> data;

    return ans;
}
