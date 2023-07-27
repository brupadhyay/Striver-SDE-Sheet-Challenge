#include <map>

/**
 * TC - O(N) { visiting all the nodes of inorder & postorder }
 * SC - O(N) { skewed tree }
*/

TreeNode<int> *buildTree(vector<int> &inOrder, int inStart, int inEnd, vector<int> &postOrder, int postStart,
                         int postEnd, map<int, int> &mpp)
{
    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(postOrder[postEnd]);
    int index = mpp[root->data];
    int nElems = inEnd - index;
    root->right = buildTree(inOrder, index + 1, inEnd, postOrder, postEnd - nElems, postEnd - 1, mpp);
    root->left = buildTree(inOrder, inStart, index - 1, postOrder, postStart, postEnd - nElems - 1, mpp);

    return root;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder,
                                              vector<int> &inOrder)
{
    TreeNode<int> *root = NULL;
    int n = postOrder.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[inOrder[i]] = i;
    }
    int inStart = 0, inEnd = n - 1;
    int postStart = 0, postEnd = n - 1;
    return buildTree(inOrder, inStart, inEnd, postOrder, postStart, postEnd, mpp);
}
