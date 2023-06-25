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


int length(Node* head){
    int n = 0;
    while(head){
        n++;
        head = head  -> next;
    }
    return n;
}


Node* findIntersection1(Node *firstHead, Node *secondHead)
{

    unordered_set<Node*> st;

    while(firstHead != nullptr){
        st.insert(firstHead);
        firstHead = firstHead -> next;
    }

    while(secondHead != nullptr){
        if(st.find(secondHead) != st.end()){
            return secondHead;
        }
        st.insert(secondHead);
        secondHead = secondHead -> next;
    }
    return NULL;
}


Node* findIntersection2(Node *firstHead, Node *secondHead)
{
    int len1 = length(firstHead);
    int len2 = length(secondHead);

    int greaterSide = len1 > len2 ? 1 : 0;
    int diff = abs(len1 - len2);
    
    Node* d1 = firstHead, *d2 = secondHead;
    if(greaterSide == 0){
        while(diff--){
            d2 = d2 -> next;
        }
    } else {
        while(diff--){
            d1 = d1 -> next;
        }
    }

    while(d1 != NULL && d2 != NULL){
        d1 = d1 -> next;
        d2 = d2 -> next;
        if(d1 == d2) return d1;
    }
    return NULL;
}


Node* findIntersection3(Node *firstHead, Node *secondHead)
{
    Node* d1 = firstHead, *d2 = secondHead;
    while(d1 != d2){
        d1 = d1 == NULL ? secondHead : d1 -> next;
        d2 = d2 == NULL ? firstHead : d2 -> next;
    }
    return d1;
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 4);

    Node* head2 = NULL;
    insertAtHead(head2, 3);
    Node* head1 = head;
    head = head -> next -> next -> next;
    head2 -> next = head;

    cout << "Printing list1\n"; 
    printList(head1);
    
    cout << "Printing list2\n"; 
    printList(head2);

    Node* intersection = findIntersection1(head1, head2);
    if(intersection == NULL){
        cout << "No intersection found\n";
    } else {
        cout << "Intersection found at "<< intersection -> data << "\n";
    }
}