#include <bits/stdc++.h> 
using namespace std;

/**
 * SORTING 
 * TC - O(N) + O(NlogN) + O(N)
 * SC - O(N)
*/
void sortStack1(stack<int> &stack)
{
	vector<int> v;
	while(!stack.empty()){
		v.push_back(stack.top());
		stack.pop();
	}
	sort(v.begin(), v.end());
	for(auto x: v){
		stack.push(x);
	}
}

/**
 * Using Recursion - inserting in decreasing fashion
 * TC - O(N^2)
 * SC - O(N) { recursive stack space }
*/

void insertInSortedWay(stack<int> &stack, int top){
	if(stack.empty() || stack.top() < top){
		stack.push(top);
		return;
	}
	
	int temp = stack.top();
	stack.pop();
	insertInSortedWay(stack, top);
	stack.push(temp);
}

void helper(stack<int> &stack){
	if(stack.empty()) return;

	int top = stack.top();
	stack.pop();
	helper(stack);
	insertInSortedWay(stack, top);
}

void sortStack2(stack<int> &stack)
{
	helper(stack);
}

int main() {
    stack<int> stack;
    int arr[] = {5, -2, 9, -7, 3};
    for(int i = 0;i<5;i++){
        stack.push(arr[i]);
    }

    sortStack2(stack);
    cout << "Stack after sorting is "<< endl;
    while(!stack.empty()){
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}
