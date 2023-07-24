#include <iostream>
#include <vector>
#include <queue>
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

Node* buildTree(Node* root){
    int data;
    cout << "Enter the data: "<< endl;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    root = new Node(data);

    cout << "Enter data for left of "<< data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for right of "<< data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

vector<int> getLevelOrder(Node* root)
{
    vector<int> v;
    queue<Node*> q;
    if(root == NULL) return {};
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            v.push_back(-1);
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
            v.push_back(front -> val);
            if(front -> left != NULL){
                q.push(front -> left);
            }
            if(front -> right != NULL){
                q.push(front -> right);
            }
        }
        
    }
    return v;
}

int main(){

    Node* root = NULL;

    root = buildTree(root);
    
    vector<int> levelOrder = getLevelOrder(root);
    for(auto it: levelOrder){
        if(it == -1) cout << endl;
        else cout << it << " ";
    }
    return 0;
}