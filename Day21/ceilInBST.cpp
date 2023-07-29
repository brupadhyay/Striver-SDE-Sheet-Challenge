/**
 * TC - O(H)
 * SC - O(1)
*/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = INT_MAX;
    while(node){
        if(node -> data >= x){
            ans = min(ans, node -> data);
        }
        if(node -> data < x){
            node = node -> right;
        } else node = node -> left;
    }
    return ans == INT_MAX ? -1 : ans;
}