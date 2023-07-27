#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        this -> val = data;
        left = NULL;
        right = NULL;
    }

};

Node* buildTree(){
    int data;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);

    root -> left = buildTree();
    root -> right = buildTree();

    return root;
}
/**
 * TC ~ O(N) + O(N) { nearabout O(N)}
 * SC - O(1)
*/

vector<int> getInorder(Node* root){
    vector<int> inorder;
    Node* curr = root;
    while(curr != NULL){
        if(curr -> left == NULL) {
            inorder.push_back(curr -> val);
            curr = curr -> right;
        }
        else {
            Node* prev = curr -> left;
            while(prev -> right && prev -> right != curr){
                prev = prev -> right;
            }
            if(prev -> right == NULL) {
                prev -> right = curr;
                curr = curr -> left;
            } 
            else {
                prev -> right = NULL;
                inorder.push_back(curr -> val);
                curr = curr -> right;
            }
        }
    }
    return inorder;
}

vector<int> getPreorder(Node* root){
    vector<int> preorder;
    Node* curr = root;
    while(curr != NULL){
        if(curr -> left == NULL) {
            preorder.push_back(curr -> val);
            curr = curr -> right;
        }
        else {
            Node* prev = curr -> left;
            while(prev -> right && prev -> right != curr){
                prev = prev -> right;
            }
            if(prev -> right == NULL) {
                prev -> right = curr;
                preorder.push_back(curr -> val);
                curr = curr -> left;
            } 
            else {
                prev -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    return preorder;
}

int main(){
    Node* root = NULL;
    root = buildTree();

    vector<int> inorder = getInorder(root);
    vector<int> preorder = getPreorder(root);

    cout << "Inorder traversal is: ";
    for(auto it: inorder){
        cout << it << " ";
    }

    cout << "\nPreorder traversal is: ";
    for(auto it: preorder){
        cout << it << " ";
    }

    return 0;
}