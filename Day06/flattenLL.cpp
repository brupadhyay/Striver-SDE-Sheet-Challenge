#include <iostream>
#include <unordered_set>
using namespace std;

/* UTILITIES FOR PRACTICE*/
class Node{
    public:
        int data;
        Node *next;
        Node* bottom;

        Node(int val){
            this -> data = val;
            next = nullptr;
            bottom = nullptr;
        }

        
};

void insertAtHead(Node* &head, int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp -> bottom != NULL){
        temp = temp -> bottom;
    }
    temp -> bottom = newNode;
}


/*Time Complexity: O(N), where N is the total number of nodes present

Reason: We are visiting all the nodes present in the given list.

Space Complexity: O(1)

Reason: We are not creating new nodes or using any other data structure.*/

Node* merge(Node* a, Node* b){
	Node* res = new Node(-1);
	Node* temp = res;

	while(a != NULL && b != NULL ){
		if(a -> data < b -> data){
			temp -> bottom = a;
			a = a -> bottom;
		} else {
			temp -> bottom = b;
			b = b -> bottom;
		}
		temp = temp -> bottom;
	}

	if(a) temp -> bottom = a;
	else temp -> bottom = b;

	return res -> bottom;
}

void printList(Node* head){
    while(head -> bottom != NULL){
        cout << head -> data << "->";
        head = head -> bottom;
    }
    cout << head -> data << "\n";
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> next == NULL) return head;

	head -> next = flattenLinkedList(head -> next);
    
	head = merge(head, head -> next);

	return head;
}


int main() {
    Node* head = NULL, *head2 = NULL, *head3 = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 7);
    insertAtHead(head, 8);
    insertAtHead(head, 10);

    insertAtHead(head2, 10);
    insertAtHead(head2, 20);

    // individually sorted
    insertAtHead(head3, 6);
    insertAtHead(head3, 12);
    insertAtHead(head3, 30);
    insertAtHead(head3, 45);

    head -> next = head2;
    head2 -> next = head3;

   
    Node* res = flattenLinkedList(head);
    printList(res);
    return 0;
}