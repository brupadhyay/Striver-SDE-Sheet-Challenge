// Clone Linked List with Random and Next Pointer
#include <iostream>
#include <unordered_map>
using namespace std;

/* UTILITIES FOR PRACTICE*/
class Node{
    public:
        int data;
        Node *next;
        Node* random;

        Node(int val){
            this -> data = val;
            next = nullptr;
            random = nullptr;
        }

        
};

void insertAtHead(Node* &head, int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}


void printList(Node* head){
    while(head -> next != NULL){
        cout << head -> data << "->";
        head = head -> next;
    }
    cout << head -> data << "\n";
}

/*
TC - O(N) + O(N)
SC - O(N)
*/

Node* copyRandomList1(Node* head) {
    Node* clonedNode = new Node(-1);
    Node* clone = clonedNode;

    Node* temp = head;
    unordered_map<Node*,Node*> mpp;
    while(temp != NULL){
        Node* newNode = new Node(temp -> data);
        mpp[temp] = newNode;
        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL){
        Node* newNode = mpp[temp];
        newNode -> next = (temp -> next) ? mpp[temp -> next] : NULL;
        newNode -> random = (temp -> random) ? mpp[temp -> random] : NULL;
        temp = temp -> next;
    }
    return mpp[head];
}


/*
TC - O(N) + O(N) + O(N)
SC - O(1)
*/
Node* copyRandomList2(Node* head) {
    if(head == NULL) return head;

    Node* orgNode = head;
    // step1: altering the links
    while(orgNode){
        Node* orgNext = orgNode -> next;
        orgNode -> next = new Node(orgNode -> data);
        orgNode -> next -> next = orgNext;
        orgNode = orgNext;
    }

    orgNode = head;
    // pointing clone node's random
    while(orgNode != NULL){
        if(orgNode -> random != NULL){
            orgNode -> next -> random = orgNode -> random -> next;
        }
        orgNode = orgNode -> next -> next;
    }

    orgNode = head;
    Node* temp = orgNode -> next;
    Node* res = temp;
    // reverting back the changes made to the links
    while(orgNode && temp){
        orgNode -> next = temp -> next;
        orgNode = orgNode -> next;

        if(orgNode) temp -> next = orgNode -> next;
        temp = temp -> next;                        
    }
    return res;
}

int main(){
    Node* head = NULL;
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;
    
    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;
    
    cout<<"Original list:\n";
    printList(head);
    
    cout<<"Copy list: \n";
    Node* newHead = copyRandomList2(head);
    printList(newHead);
    return 0;
}