/**
 * Using Inorder Traversal
 * TC - O(nlogn) 
 * SC - O(logn) { worst case - skewed-tree will also take logn }
*/
TreeNode<int>* buildTree(vector<int> &preOrder, int st, int end){
    if(st > end){
        return NULL;
    }

    int mid = (st + end)/2;
    TreeNode<int> *root = new TreeNode<int> (preOrder[mid]);
    root -> left = buildTree(preOrder, st, mid-1);
    root -> right = buildTree(preOrder, mid+1, end);

    return root;
}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    sort(preOrder.begin(), preOrder.end());
    int n = preOrder.size();
    return buildTree(preOrder, 0, n-1);
}

/**
 * Using range to decide whether to populate or not
 * TC - O(N)
 * SC - O(N) { recursive stack space }
*/ 

TreeNode<int> * buildTree(vector<int> preOrder, int maxi, int &st){
    if(st >= preOrder.size() || preOrder[st] >= maxi){
        return NULL;
    }

    TreeNode<int> *root = new TreeNode<int> (preOrder[st++]);
    root -> left = buildTree(preOrder, root -> data, st);

    root -> right = buildTree(preOrder, maxi, st);
    
    return root;
}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int maxi = INT_MAX;
    int n = preOrder.size();
    int st = 0;
    return buildTree(preOrder, maxi, st);
}