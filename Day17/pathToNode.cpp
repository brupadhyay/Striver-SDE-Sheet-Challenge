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
    cin >> data;
    if(data == -1) return NULL;
    root = new Node(data);

    root -> left = buildTree(root -> left);
    root -> right = buildTree(root -> right);
    return root;
}
/**
 * Using path tracking and recursion
 * TC - O(n)
 * SC - O(h) 
 * where n is nodes and h is height of Binary Tree
*/
void recur(Node *root, int x, vector<int> &path){
	if(root == NULL) return;
	path.push_back(root -> val);
	if(path.back() == x) return;
	recur(root -> left, x, path);
	recur(root -> right, x, path);
	if(path.back() != x) path.pop_back();
}

vector<int> pathInATree(Node *root, int x)
{
	vector<int> path;
	recur(root, x, path);
	return path;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout << "enter target ";
    int nodeToReach;
    cin >> nodeToReach;

    vector<int> path = pathInATree(root, nodeToReach);
    for(int i = 0;i<path.size()-1;i++){
        cout << path[i] << " -> ";
    }
    cout << path[path.size()-1];

    return 0;
}