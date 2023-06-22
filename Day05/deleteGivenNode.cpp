#include <iostream>
using namespace std;

/* UTILITIES FOR PRACTICE*/
class ListNode{
    public:
        int data;
        ListNode *next;

        ListNode(int val){
            this -> data = val;
            next = nullptr;
        }

        
};

void insertAtHead(ListNode* &head, int val){
    ListNode *newNode = new ListNode(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

ListNode* getReference(ListNode* head, int val){
    while(head -> data != val){
        head = head -> next;
    }
    return head;
}

void deleteNode(ListNode *node) {
    int valueOfNextNode = node -> next -> data;
    node -> data = valueOfNextNode;
    node -> next = node -> next -> next;
}

//printing the list function
void printList(ListNode* head) {
    while(head->next != NULL) {
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<head->data<<"\n";
}

int main(){
    ListNode* head = NULL;
    int v[] = {1, 2, 3, 4, 5, 6};
    for(int i = 0;i<6;i++){
        insertAtHead(head, v[i]);
    }
    printList(head);
    ListNode* nodeToBeDeleted = getReference(head, 4);
    deleteNode(nodeToBeDeleted);
    cout << "After deleting \n";
    printList(head);
}