/**
 * TC - O(N) { using level order traversal }
 * SC - O(N) { queue }
*/
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL) return true;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        for(int i = 0;i<size;i++){
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            temp.push_back(front -> data);

            if(front -> left){
                q.push(front -> left);
            }
            if(front -> right){
                q.push(front -> right);
            }
        }
        int n = temp.size();
        for(int i = 0;i<n/2;i++){
            if(temp[i] != temp[n - i - 1]) return false;
        }

    }
    return true;
}

/*
Time Complexity: O(N)

Reason: We are doing simple tree traversal and changing 
both root1 and root2 simultaneously.

Space Complexity: O(H)

Reason:  In the worst case, the recursion depth can be equal to the 
height of the tree. Since the function calls are made for 
both the left and right subtrees at each level*/

bool isSymmetricUtil(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(!root1 || !root2){
        return root1 == root2;
    }

    return (root1 -> data == root2 -> data ) &&
    isSymmetricUtil(root1 -> left, root2 -> right) &&
    isSymmetricUtil(root1 -> right, root2 -> left);
}


bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL) return true;
    return isSymmetricUtil(root -> left, root -> right);
}