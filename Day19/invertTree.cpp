/**
 * TC - O(n)
 * SC - O(n)
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode* > q;
        if(!root) return NULL;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            swap(front -> left, front -> right);

            if(front -> left){
                q.push(front -> left);
            }
            if(front -> right){
                q.push(front -> right);
            }
        }
        return root;
    }
};