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


void printList(Node* head){
    while(head -> next != NULL){
        cout << head -> data << "->";
        head = head -> next;
    }
    cout << head -> data << "\n";
}


/*BRUTE FORCE - for every k we connect last node to the first
TC - O(k*n) { for every k we go to end and then changing links}
SC - O(1)
*/
Node *rotate1(Node *head, int k) {
    if(head == NULL || head -> next == NULL) return head;
    for(int i = 0;i<k;i++){
        Node* temp = head;
        // we have to stop before, to disconnect tail from the previous node
        while(temp -> next -> next != NULL) temp = temp -> next;
        Node* endingNode = temp -> next;
        temp -> next = NULL;  
        endingNode -> next = head;
        head = endingNode;              
    }
    return head;
}

/*OPTIMAL APPROACH
- we first eliminate complexity of k by k % n becz every array repeats after k rotations
- then we connect tail to head
- then point head to (n-k+1)th node, 
- and try to disconnect (n-k)th node 
TC - O(N) { for calculating length } + O(N - (k%N)) { to travel till N-kth node}
SC - O(1)
*/

Node *rotate2(Node *head, int k) {
    // bcz we stop at tail so len should be initialized with 1
    int len = 1;
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
        len++;
    }

    k = k%len;

    len = len - k;

    // connect tail to head
    temp -> next = head;

    Node* end = head;
    while(--len){
        end = end -> next;
    }
    
    // move head to new head of rotated Linked List
    head = end -> next;
    
    // point end to null
    end -> next = NULL; 

    return head;
}

int main(){
    Node* head = NULL;
    int k = 2;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    
    cout<<"Original Linked List: "; printList(head);
    Node* res = rotate2(head, k);
    cout<<"After k rotation: "; printList(res);

    return 0;
}