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

void createACycle(Node* &head, int pos){
    Node* temp = head;
    Node* ptr = head;
    int cnt = 0;
    while(temp -> next != NULL){
        if(cnt != pos){
            cnt++;
            ptr = ptr -> next;
        }
        temp = temp -> next;
    }
    temp -> next = ptr;
}

/*TC - O(N) SC - O(N)*/
Node* detectCycle(Node *head){
    unordered_set<Node*> st;
    Node* dummy = head;
    while(dummy != NULL){
        if(st.count(dummy)) return dummy;
        st.insert(dummy);
        dummy = dummy -> next;
    }
    return NULL;
}

/*
TC - O(N) Reason: We can take overall iterations and club them to O(N)
SC - O(1)
*/
Node *getCyclicNode(Node *head){
    Node* slow = head, *fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(){
    Node* head = NULL;

    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,6);
    insertAtHead(head,10);

    createACycle(head, 2);

    Node* cyclicNode = getCyclicNode(head);
    if(cyclicNode == NULL) {
        cout << "No cycle found\n";
    } else {
        int cnt = 0;
        Node* temp = head;
        while(temp != cyclicNode){
            temp = temp -> next;
            cnt++;
        }
        cout << "Cycle present at position "<< cnt;
    }

    return 0;
}