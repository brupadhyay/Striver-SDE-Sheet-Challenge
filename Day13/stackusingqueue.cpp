#include <queue>
#include <iostream>
using namespace std;

/**
 * TC - O(n)
 * SC - O(n)
*/

class Stack {
	// Define the data members.
    queue<int> q;

   public:
    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        if(q.size()) return false;
        return true;
    }

    void push(int element) {
        q.push(element);
        for(int i = 1;i<=q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() { 
        if(q.size() == 0) return -1;
        
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        if(q.size() == 0) return -1;
        return q.front();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "the element at top is "<< s.top() << endl;
    cout << "the size is "<< s.getSize() << endl;
    cout << "the element removed from top is "<< s.pop() << endl;
    cout << "the size is "<< s.getSize() << endl;
    cout << "the element removed from top is "<< s.pop() << endl;
}