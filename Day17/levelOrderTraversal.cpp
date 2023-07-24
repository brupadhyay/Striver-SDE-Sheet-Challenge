/**
 * TC - O(N)
 * SC - O(N)
*/

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> v;
    queue<BinaryTreeNode<int>*> q;
    if(root == NULL) return {};
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        v.push_back(front -> val);
        if(front -> left != NULL){
            q.push(front -> left);
        }
        if(front -> right != NULL){
            q.push(front -> right);
        }
    }
    return v;
}