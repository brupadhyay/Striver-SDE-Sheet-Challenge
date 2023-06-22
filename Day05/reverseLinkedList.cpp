
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


/*
Naive Approach - Iterative Solution
TC - O(N)
SC - O(1)
*/
ListNode *reverseList1(ListNode *head){

    // step 1
    ListNode *prev_p = NULL;
    ListNode *current_p = head;
    ListNode *next_p;

    // step 2
    while (current_p){

        next_p = current_p->next;
        current_p->next = prev_p;

        prev_p = current_p;
        current_p = next_p;
    }

    head = prev_p; // step 3
    return head;
}

/*
Recursive Solution
TC - O(n)
SC - O(1)
*/

ListNode *reverseList2(ListNode *&head){
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *nnode = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return nnode;
}

int main() {
    ListNode* head = NULL;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int val;
        cin >> val;
        insertAtHead(head, val);
    }

    ListNode* reversedHead = reverseList1(head);
    cout << "Reversed List is \n";
    while(reversedHead != NULL){
        cout << reversedHead -> data << " -> ";
        reversedHead = reversedHead -> next;
    }
    cout << "-1";
    return 0;
}