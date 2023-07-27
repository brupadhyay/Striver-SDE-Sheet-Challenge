#include <bits/stdc++.h> 
/*
Time Complexity: O(N).

Reason: We are doing a tree traversal.

Space Complexity: O(N)

Reason: Space is needed for the recursion stack. 
In the worst case (skewed tree), space complexity can be O(N).*/

long long int findMax(TreeNode<int>* root, long long int val, int &cnt, long long int &ans){
    if(root == NULL){
        return 0;
    }

    long long int leftSum = findMax(root -> left, val, cnt, ans);
    long long int rightSum = findMax(root -> right, val, cnt, ans);

    if(leftSum == 0 && rightSum == 0) cnt++;

    long long int currSum = leftSum + rightSum + root -> val;
    ans = max(ans, currSum);

    return max(leftSum, rightSum) + root -> val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    long long int ans = 0;
    int cnt = 0;
    findMax(root, 0, cnt, ans);
    return cnt > 1 ? ans : -1; 
}