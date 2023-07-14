#include <bits/stdc++.h> 
using namespace std;

/**
 * TC -
 * 1. isempty - O(1)
 * 2. dequeue - O(1)
 * 3. enqueue - O(1)
 * 4. top - O(1)
 * SC - O(N)
*/

class Queue {
    int *arr;
    int currsize;
    int front;
    int rear;
    int maxsize;
public:
    Queue(int capacity) {
        maxsize = capacity;
        currsize = 0;
        front = -1;
        rear = -1;
        arr = new int[capacity];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return currsize == 0;
    }

    void enqueue(int data) {
        if(currsize == maxsize){
            cout << "Queue is full\n";
            return;
        }
        if(rear == -1){
            front = 0;
            rear = 0;
        } else rear = (rear + 1) % maxsize;

        arr[rear] = data;
        cout << "the element is pushed " << data << endl;
        currsize++;
    }

    int dequeue() {
        if(front == -1){
            cout << "Queue is empty\n";
            return -1;
        }
        int popped = arr[front];
        if(currsize == 1){
            front = -1;
            rear = -1;
        } else front = (front + 1) % maxsize;
        currsize--;
        return popped;
    }

    int top() {
        if(front == -1){
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
  Queue q(6);
  q.enqueue(4);
  q.enqueue(14);
  q.enqueue(24);
  q.enqueue(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The first element to be deleted " << q.dequeue() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;

  return 0;
}