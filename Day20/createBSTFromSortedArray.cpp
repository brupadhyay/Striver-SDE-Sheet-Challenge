/**
 * TC - O(n) where 'n' is the number of elements in the input array.
 * SC - O(logn) { recurive stack space }
 *  the maximum depth of the call stack is log(n), 
 * and the space complexity is O(log n).
*/

TreeNode<int>* createBST(vector<int> &arr, int st, int end){
    if(st > end) return NULL;

    int mid = (st + end)/2;
    TreeNode<int> * root = new TreeNode<int> (arr[mid]);
    root -> left = createBST(arr, st, mid - 1);
    root -> right = createBST(arr, mid + 1, end);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return createBST(arr, 0, n - 1);
}