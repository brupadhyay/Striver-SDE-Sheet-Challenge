/*Time Complexity: O(max(m,n)). Assume that m and n represent the length of num1 and num2 respectively, the algorithm above iterates at most max(m,n) times.

Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.*/
Node *addTwoNumbers(Node *num1, Node *num2)
{

    if(num1 == NULL){
        return num2;
    } 
    if(num2 == NULL){
        return num1;
    }

    Node* res = new Node(-1);
    Node* curr = res;

    int carry = 0;
    while(num1 != NULL || num2 != NULL || carry){
        int sum = 0;
        if(num1 != NULL){
            sum += num1 -> data;
            num1 = num1 -> next;
        } 
        if(num2 != NULL){
            sum += num2 -> data;
            num2 = num2 -> next;
        }

        sum += carry;
        carry = sum/10;
        sum = sum%10;

        curr -> next = new Node(sum);
        curr = curr -> next;
    }

    return res -> next;
}
