/**
 * Using level order traversal and indexing
 * TC - O(n)
 * Reason: We are doing a simple level order traversal. 
 * The inner loop simply traverses the nodes 
 * level-wise and doesn’t add to the complexity.
 * SC - O(n)
*/

// * if says about non-null count simply take maximum 
// * of size of queue at diff.levels

int widthOfBinaryTree(TreeNode* root) {
    int ans = 0;
    if(root == NULL) return ans;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int leftMost, rightMost;
        for(int i = 0;i<size;i++){
            TreeNode *front = q.front().first;
            int ind = q.front().second;
            q.pop();

            if(i == 0) leftMost = ind;
            if(i == size - 1) rightMost = ind;

            if(front -> left){
                q.push({front -> left, 1LL*2*ind + 1});
            }
            if(front -> right){
                q.push({front -> right, 1LL*2*ind + 2});
            }
        }
        ans = max(ans, rightMost - leftMost + 1);
    }
    return ans;
}