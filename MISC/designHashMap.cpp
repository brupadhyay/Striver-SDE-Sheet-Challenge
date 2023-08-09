/**Using Linked List
 * * OR Using BST -> Search/Insertion/Deletion - O(logn)
*/

#include <iostream>
using namespace std;

class BSTNode{
    public:

    int key, val;
    BSTNode* left, * right;
    

    BSTNode(int k, int v){
        this -> key = k;
        this -> val = v;
        left = right = NULL;
    }
};

BSTNode* insertInBST(BSTNode* root, BSTNode* node){
    if(root == NULL){
        return node;
    }

    if(root -> key > node -> key){
        root -> left = insertInBST(root -> left, node);
    } else if(root -> key < node -> key){
        root -> right = insertInBST(root -> right, node);
    }

    return root;
}

BSTNode* search(BSTNode* root, int key){
    BSTNode* curr = root;

    while(curr != NULL){
        if(curr -> key == key){
            return curr;
        }

        if(curr -> key > key){
            curr = curr -> left;
        } else {
            curr = curr -> right;
        }
    }
    return NULL;
}

BSTNode* deletionInBST1(BSTNode* root, int key){
    // if tree is empty
    if(root == NULL){
        return root;
    }

    if(root -> key < key){
        root -> right = deletionInBST1(root -> right, key);
        return root;
    } else if(root -> key > key){
        root -> left = deletionInBST1(root -> left, key);
        return root;
    }
    // coming here means curr node is to be deleted
    if(root -> left == NULL){
        BSTNode* temp = root -> left;
        delete root;
        return temp;
    } else if(root -> right == NULL){
        BSTNode* temp = root -> left;
        delete root;
        return temp;
    }
    else {        
        // if node has two childrens
        // finding inorder successor
        BSTNode* succParent = root;
        BSTNode* succ = root -> right;
        while(succ -> left != NULL){
            succParent = succ;
            succ = succ -> left;
        }
        if(succParent != root){
            // * very important step
            succParent -> left = succ -> right;
        } else {
            // skewed tree
            succParent -> right = succ -> right;
        }
        root -> key = succ -> key;
        root -> val = succ -> val;
        
        delete succ;
        return root;
    }    
}

BSTNode* deletionInBST2(BSTNode* root, int key){
    // if tree is empty
    if(root == NULL){
        return root;
    }

    if(root -> key < key){
        root -> right = deletionInBST2(root -> right, key);
        return root;
    } else if(root -> key > key){
        root -> left = deletionInBST2(root -> left, key);
        return root;
    }
    // coming here means curr node is to be deleted
    if(root -> left == NULL){
        BSTNode* temp = root -> right;
        delete root;
        return temp;
    } else if(root -> right == NULL){
        BSTNode* temp = root -> left;
        delete root;
        return temp;
    }
    else {        
        // if node has two childrens
        // finding inorder predecessor
        BSTNode* succParent = root;
        BSTNode* succ = root -> left;
        while(succ -> right != NULL){
            succParent = succ;
            succ = succ -> right;
        }
        if(succParent != root){
            // * very important step
            succParent -> right = succ -> left;
        } else {
            // skewed tree
            succParent -> left = succ -> left;
        }
        root -> key = succ -> key;
        root -> val = succ -> val;
        
        delete succ;
        return root;
    }    
}

void inorder(BSTNode* root){
    if(!root) return;

    inorder(root -> left);
    cout << root -> key << " ";
    inorder(root -> right);
}

int main(){
    BSTNode* root = NULL;

    root = insertInBST(root, new BSTNode(12, 32));
    root = insertInBST(root, new BSTNode(50, 23));
    root = insertInBST(root, new BSTNode(60, 6));
    root = insertInBST(root, new BSTNode(70, 7));
    root = insertInBST(root, new BSTNode(55, 11));
    root = insertInBST(root, new BSTNode(10, 100));
    root = insertInBST(root, new BSTNode(15, 3));
    root = insertInBST(root, new BSTNode(40, 4));
    root = insertInBST(root, new BSTNode(5, 12));
    root = insertInBST(root, new BSTNode(65, 12));
    root = insertInBST(root, new BSTNode(68, 12));

    BSTNode* findNode1 = search(root, 40);
    if(findNode1 != NULL){
        cout << findNode1 -> val << endl;
    } else {
        cout << "key is not present in hashmap " << endl;
    }
    inorder(root);
    cout << "\nAfter deletion \n";
    root = deletionInBST2(root, 40);
    
    inorder(root);
    root = deletionInBST2(root, 60);
    cout << "\nAfter deletion of 60 \n";
    inorder(root);
    return 0;
}