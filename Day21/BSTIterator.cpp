#include <bits/stdc++.h> 
using namespace std;

class BSTNode{
    public:
    int val;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int data){
        this -> val = data;
        left = right = NULL;
    }
};

BSTNode* insertIntoBST(BSTNode* root, int data){
    if(root == NULL){
        return new BSTNode(data);
    }
    if(data < root -> val){
        root -> left = insertIntoBST(root -> left, data);
    } else {
        root -> right = insertIntoBST(root -> right, data);
    }

    return root;
}

class BSTiterator
{
    public:
    BSTNode *root;
    stack<BSTNode *> st;
    BSTiterator(BSTNode *root)
    {
        root = root;
        BSTNode *cur = root;
        while(cur){
            st.push(cur);
            cur = cur -> left;
        }
    }

    int next()
    {
        BSTNode *ans = NULL;
        if(!st.empty()){
            ans = st.top();
            st.pop();
        }
        if(ans -> right){
            BSTNode *pre = ans -> right;
            // right is present then push it because it minimum from root
            st.push(pre);
            // push all the leftmost nodes becz they are minimum
            while(pre -> left){
                pre = pre -> left;
                st.push(pre);
            }
            
        }
        return ans -> val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};


int main(){
    vector<int> nodes = {14, 5, 16, 1, 8, 15, 19, 13, 20 };
    int n = nodes.size();
    BSTNode* root = NULL;
    for(int i = 0;i<n;i++){
        root = insertIntoBST(root, nodes[i]);
    }

    BSTiterator bst(root);
    for(int i = 0;i<n;i++){
        cout << "Next Smaller Element is "<< bst.next() << endl;
        cout << "has next or not "<< bst.hasNext() << endl;
    }

    return 0;
    
}