#include <iostream>
#include <vector>
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
NAIVE APPROACH - finding length and going till the middle
TC - O(n) + O(n/2) ~ O(n)
SC - O(1)
*/

ListNode* middleNode(ListNode* head) {
    int n = 0;
    ListNode* temp = head;
    while(temp) {
        n++;
        temp = temp -> next;
    }
    
    temp = head;
    
    for(int i = 0; i < n / 2; i++) {
        temp = temp -> next;
    }
    
    return temp;
}

/*
Tortoise Hare Approach - using fast and slow pointers
- we reduce complexity by not finding the length
TC - O(n)
SC - O(1)
*/
ListNode *findMiddle(ListNode *head) {
    ListNode* slow = head, *fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}


int main() {
    ListNode* head = NULL;
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for(int i = 0;i<v.size();i++){
        insertAtHead(head, v[i]);
    }

    ListNode *middle = findMiddle(head);
    cout << "Middle Node is " << middle -> data; 

    
    return 0;
}