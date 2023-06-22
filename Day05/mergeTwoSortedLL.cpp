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
Using Extra Space to store merged sorted list
TC - O(N+M)
SC - O(N+M)
*/


ListNode* sortTwoLists1(ListNode* first, ListNode* second)
{
    if(first == NULL) {
        return second;
    }
    if(second == NULL) {
        return first;
    }


    ListNode *res = new ListNode(0);
    ListNode *dummy = res;
    ListNode *temp1 = first;
    ListNode *temp2 = second;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> data <= temp2 -> data){
            dummy -> next = temp1;
            temp1 = temp1 -> next;
            
        } else {
            dummy -> next = temp2;
            temp2 = temp2 -> next;
            
        }
        dummy = dummy -> next;
    }
    while(temp1 != NULL){
        dummy -> next = temp1;
        temp1 = temp1 -> next;
        dummy = dummy -> next;
    }

    while(temp2 != NULL){
        dummy -> next = temp2;
        temp2 = temp2 -> next;
        dummy = dummy -> next;
    }
    return res -> next;
}

/*
Without using extra space - 
TC - O(N+M)
SC - O(1)
*/

ListNode* sortTwoLists2(ListNode* first, ListNode* second)
{
    if(first == NULL) {
        return second;
    }
    if (second == NULL) {
      return first;
    }
    
    if(first -> data > second -> data){
        swap(first, second);
    }
    
    ListNode *res = first;
    
    while(first != NULL && second != NULL){
        ListNode *temp = NULL;
        while(first != NULL && first -> data <= second -> data){
            temp = first;
            first = first -> next;
        }
        
        temp -> next = second;
        swap(first, second);      
    }

    return res;
}

int main(){
    ListNode *head1 = NULL,*head2 = NULL;
    vector<int> v1({3,7,10}), v2({1,2,5,8,10});
    for(auto it: v1){
        insertAtHead(head1, it);
    }
    for(auto it: v2){
        insertAtHead(head2, it);
    }

    ListNode *mergedList = sortTwoLists2(head1, head2);
    while(mergedList != NULL){
        cout << mergedList -> data << " ";
        mergedList = mergedList -> next;
    }    
    return 0;
}