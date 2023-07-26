#include <bits/stdc++.h> 

/**
 * Using level order traversal and keeping track of insertion
 * TC - O(n)
 * SC - O(n)
*/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if(root == NULL) return v;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool leftToRight = 1;
    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i = 0;i<size;i++){
            BinaryTreeNode<int>* front = q.front();
            q.pop();

            int indexToFill = leftToRight ? i : size - i - 1;
            temp[indexToFill] = front -> data;

            if(front -> left != NULL){
                q.push(front -> left);
            }
            if(front -> right != NULL){
                q.push(front -> right);
            }
        }
        leftToRight = !leftToRight;
        for(auto x: temp){
            v.push_back(x);
        }        
    }
    return v;    
}
