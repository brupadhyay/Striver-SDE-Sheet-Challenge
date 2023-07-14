#include <stack>
#include <iostream>
using namespace std;

/**
 * Solution 1 - using two stacks
 * TC - O(N) { push operation }
 * SC - O(2N)
*/

class Queue1 {
    // Define the data members(if any) here.
    stack<int> input, output;
    public:

    void enQueue(int val) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(val);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int deQueue() {
        if(input.empty()) return -1;
        int ans = input.top();
        input.pop();
        return ans;
    }

    int peek() {
        if(input.size() == 0) return -1;
        return input.top();
    }

    bool isEmpty() {
        return input.empty();
    }
};

/**
 * Using Push in ammortized O(1)
 * TC - O(1)
 * SC - O(2N)
*/

class Queue2 {
    // Define the data members(if any) here.
    stack<int> input, output;
    public:

    void enQueue(int val) {
        input.push(val);
    }

    int deQueue() {
        if(input.empty() && output.empty()) return -1;

        // * important if empty then we fill
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    int peek() {
        if(input.empty() && output.empty()) return -1;
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

int main() {
  Queue1 q;
  q.enQueue(3);
  q.enQueue(4);
  cout << "The element poped is " << q.deQueue() << endl;
  q.enQueue(5);
  cout << "The top of the queue is " << q.peek() << endl;
  cout << "the queue is empty or not " << q.isEmpty() << endl;
}