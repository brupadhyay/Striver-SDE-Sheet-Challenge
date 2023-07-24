/**
 * Using visited levels
 * TC - O(n) + O(log(h)) { where h is height of Binary Tree and n is no. of nodes}
 * SC - O(h) + O(h) { set data structure and recursion stack space }
*/

void getLeft(TreeNode<int>* root, int level, set<int> &st, vector<int> &v){
    if(root == NULL) return;
    if(st.find(level) == st.end()){
        v.push_back(root -> data);
        st.insert(level);
    }
    getLeft(root -> left, level + 1, st, v);
    getLeft(root -> right, level + 1, st, v);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    int level = 0;
    set<int> st;
    vector<int> v;
    getLeft(root, level, st, v);
    return v;
}

/**
 * Without set data structure
 * TC - O(N)
 * SC - O(h) { height of binary tree recursive stack space }
*/

void getLeft(TreeNode<int>* root, int level, vector<int> &v){
    if(root == NULL) return;
    if(level == v.size()){
        v.push_back(root -> data);
    }
    getLeft(root -> left, level + 1, v);
    getLeft(root -> right, level + 1, v);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> v;
    getLeft(root, 0, v);
    return v;
}