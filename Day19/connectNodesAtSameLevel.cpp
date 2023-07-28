/**
 * Using level order traversal
 * TC - O(N)
 * Auxiliary Space - O(N) { worst case }
*/

void connectNodes(BinaryTreeNode< int > *root) {
    if(!root) return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<BinaryTreeNode<int>*> levelNodes;
        for(int i = 0;i<size;i++){
            BinaryTreeNode<int> * front = q.front();
            q.pop();

            levelNodes.push_back(front);
            if(front -> left){
                q.push(front -> left);
            }
            if(front -> right){
                q.push(front -> right);
            }
        }
        for(int i = 0;i<levelNodes.size()-1;i++){
            levelNodes[i] -> next = levelNodes[i+1];
        }
    }
}