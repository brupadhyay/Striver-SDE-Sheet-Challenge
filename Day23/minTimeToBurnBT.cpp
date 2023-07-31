/**
 * TC - O(n) + O(n) { creating parent map and level order for burning }
 * SC - O(n) { parent map } + O(n) { visited map } + O(n) { queue } 
*/
class Solution {
    void connectParents(TreeNode* root, map<TreeNode*, TreeNode*> &parentNodeMap, TreeNode* &infected, int start){
        queue<TreeNode*> q;
        q.push(root);

        parentNodeMap[root] = NULL;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node -> val == start){
                infected = node;
            }

            if(node -> left){
                parentNodeMap[node -> left] = node;
                q.push(node -> left);
            }
            if(node -> right){
                parentNodeMap[node -> right] = node;
                q.push(node -> right);
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
    
        // finding parents of nodes
        map<TreeNode*, TreeNode*> parentNodeMap;

        TreeNode* infected = NULL;

        connectParents(root, parentNodeMap, infected, start);


        queue<pair<TreeNode*, int>> q;
        int maxTime = 0;
        q.push({infected, 0});

        map<TreeNode*, bool> vis;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int time = q.front().second;
            q.pop();

            vis[node] = true;

            maxTime = max(maxTime, time);

            // parent
            TreeNode* parent = parentNodeMap[node];
            if(vis[parent] == false && parent != NULL){
                vis[parent] = true;
                q.push({parent, time + 1});
            }

            if(node -> left != NULL && vis[node -> left] == false){
                q.push({node -> left, time + 1});
                vis[node -> left] == true;
            }
            if(node -> right != NULL && vis[node -> right] == false){
                q.push({node -> right, time + 1});
                vis[node -> right] == true;
            }

        }
        return maxTime;
    }
};