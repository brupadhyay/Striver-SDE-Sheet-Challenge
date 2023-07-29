/**
 * TC - O(N) + O(N) { inorder and pair check }
 * SC - O(N) + O(N) { for inorder vector and recursive stack space } 
*/

void getInorder(BinaryTreeNode<int> *root, vector<int> &inorder){
    if(!root) return;

    getInorder(root -> left, inorder);
    inorder.push_back(root -> data);
    getInorder(root -> right, inorder);    
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> inorder;
    getInorder(root, inorder);
    int n = inorder.size();
    int i = 0, j = n-1;
    while(i < j){
        int sum = inorder[i] + inorder[j];
        if(sum == k) return true;
        else if(sum < k){
            i++;
        } else {
            j--;
        }
    }
    return false;
}