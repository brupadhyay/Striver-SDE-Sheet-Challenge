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

void createACycle(Node* &head){
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
}

/*TC - O(N) SC - O(N)*/
bool detectCycle1(Node *head){
    unordered_set<Node*> st;
    Node* dummy = head;
    while(dummy != NULL){
        if(st.count(dummy)) return true;
        st.insert(dummy);
        dummy = dummy -> next;
    }
    return false;
}

/*TC - O(N) SC - O(1)*/
bool detectCycle2(Node *head){
    Node* slow = head, *fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);

    createACycle(head);


    if(detectCycle2(head) == true)
    cout<<"Cycle detected\n";
    else
    cout<<"Cycle not detected\n";
    return 0;
}

