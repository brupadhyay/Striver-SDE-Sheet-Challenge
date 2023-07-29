/**
 * TC - O(N) { for level order traversal }
 * SC - O(N) { for queue and stringstream }
*/
string serializeTree(TreeNode<int> *root)
{
    if(!root) return "";
    string s;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *front = q.front();
        q.pop();
        if(front == NULL) s.append("#,");
        else s.append(to_string(front -> data) + ",");

        if(front != NULL){
            q.push(front -> left);
            q.push(front -> right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.size() == 0) return NULL;
    stringstream s(serialized);
    string str;
    getline(s, str, ',');
    TreeNode<int> *root = new TreeNode<int> (stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *front = q.front();
        q.pop();

        getline(s,str, ',');
        if(str == "#"){
            front -> left = NULL;
        } else {
            TreeNode<int> *left = new TreeNode<int> (stoi(str));
            front -> left = left;
            q.push(left);
        }

        getline(s,str, ',');
        if(str == "#"){
            front -> right = NULL;
        } else {
            TreeNode<int> *right = new TreeNode<int> (stoi(str));
            front -> right = right;
            q.push(right);
        }
    }
    return root;
}
