#include <iostream>
#include <unordered_set>
using namespace std;

/* UTILITIES FOR PRACTICE*/
class Node{
    public:
        int data;
        Node *next;

        Node(int val){
            this -> data = val;
            next = nullptr;
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

int getLength(Node* head){
    Node* temp = head;
    int n = 0;
    while(temp){
        temp = temp -> next;
        n++;
    }
    return n;
}

/*TC - O(N/k*k) SC - O(N/k*k)*/

Node* reverseKGroup(Node* head, int k) {
    int length = getLength(head);

    if(length < k) return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* nxt;
    int cnt = k;
    while(cnt--){
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }

    length -= k;

    if(length >= k){
        head -> next = reverseKGroup(nxt, k);
    } else {
        head -> next = nxt;
    }

    return prev;
}

/*TC - O(N/k*k) SC - O(1)*/
Node* reverseKGroup2(Node* head, int k) {
    if(head == NULL || head -> next == NULL) return head;
    Node* dummy = new Node(-1);
    Node* prev = dummy, *curr = prev, *nex = prev;
    prev -> next = head;

    int length = 0;
    while(curr -> next != NULL){
        length++;
        curr = curr -> next;
    }

    while(length >= k){
        curr = prev -> next;
        nex = curr -> next;
        for(int i = 1;i<k;i++){
            curr -> next = nex -> next;
            nex -> next = prev -> next;
            prev -> next = nex;
            nex = curr -> next;
        }
        length -= k;
        prev = curr;
    }
    return dummy -> next;
}

void printList(Node* head){
    while(head -> next != NULL){
        cout << head -> data << "->";
        head = head -> next;
    }
    cout << head -> data << "\n";
}

int main(){
    Node* head = NULL;
    int k = 3;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,7);
    insertAtHead(head,8);
    
    cout<<"Original Linked List: "; printList(head);
    cout<<"After Reversal of k Nodes: "; 
    Node* newHead = reverseKGroup2(head,k);
    printList(newHead);

    return 0;
}