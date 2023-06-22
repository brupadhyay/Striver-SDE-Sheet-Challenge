/*
Naive Approach
TC - O(n) + O(n-k)
SC - O(1)
*/


Node* removeKthNode(Node* head, int K)
{
    Node *curr = head;
    int length = 0;
    while(curr != NULL){
        length++;
        curr = curr -> next;
    }
    curr = head;
    int distance = length - K;

    if(distance == 0) return head -> next;

    for(int i = 0;i<distance-1;i++){
        curr = curr -> next;
    }
    curr -> next = curr -> next -> next;
    return head;
}

/*
Two Pointer Approach
TC - O(n)
SC - O(1)
*/
Node* removeKthNode(Node* head, int K)
{
    Node* slow = head, *fast = head;
    while(K--){
        fast = fast -> next;
    }

    if(fast == NULL){
        return slow -> next;
    }

    while(fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = slow -> next -> next;
    return head;    
}