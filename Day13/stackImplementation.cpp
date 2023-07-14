#include <bits/stdc++.h> 
using namespace std;

/**
 * TC - O(N)
 * SC - O(N)
*/

class Stack {
    int size;
    int *arr;
    int index;
public:
    
    Stack(int capacity) {
        size = capacity;
        index = -1;
        // ! important
        arr = new int[size];
    }

    void push(int num) {
        if(index == size - 1) return;
        index++;
        arr[index] = num;
    }

    int pop() {
        if(index == -1){
            return -1;
        }
        int ans = arr[index];
        index--;
        return ans;
    }
    
    int top() {
        if(index == -1) return -1;
        return arr[index];
    }
    
    int isEmpty() {
        return index == -1 ? 1 : 0;
    }
    
    int isFull() {
        return index == size - 1 ? 1 : 0;
    }
};

int main(){

    Stack s(4);
    s.push(2);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.top() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.isFull() << endl;
    cout << "Top of stack after deleting an element " << s.top() << endl;
    return 0;


    return 0;
}