#include <iostream>
#include <vector>
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

/*
TC - O(n) + O(n/2)
SC - O(n)*/
bool isPalindrome1(Node *head) {
    vector<int> arr;
    Node *temp = head;
    while(temp != NULL){
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    int n = arr.size();
    for(int i = 0;i<n/2;i++){
        if(arr[i] != arr[n-i-1]) return false;
    }
    return true;
}


/*TC - O(n/2) + O(n/2) + O(n/2)
SC - O(1)
*/

Node* findMiddle(Node *head){
    Node* slow = head, *fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

bool isPalindrome2(Node *head) {
    
    Node* mid = findMiddle(head);

    Node *prev = NULL, *curr = mid;
    while(curr != NULL){
        Node* nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    Node* reversedHead = prev;
    
    Node* temp = head;
    while(reversedHead != NULL){
        if(temp -> data != reversedHead -> data) return false;
        reversedHead = reversedHead -> next;
        temp = temp -> next;
    }
    return true;    
}


int main(){
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    
    cout << "Linked List ";
    isPalindrome2(head) ? cout << "is palindrome" : cout<< "not a palindrome" << endl;

    return 0;
}