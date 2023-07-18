#include <bits/stdc++.h> 
using namespace std;

#define n 5

/*
Time Complexity: O(N), The total number of comparisons is 3(N-1).
Auxiliary Space: O(N), n extra space is needed to store the stack.
*/

int findCelebrity(int party[][n]) {
	stack<int> st;
	for(int i = 0;i<n;i++){
		st.push(i);
	}	
	while(st.size() > 1){
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();

		if(party[a][b]){
			st.push(b);
		} else if(party[b][a]){
			st.push(a);
		}
	}
	if(st.empty()) return -1;

	int celebrity = st.top();
	for(int i = 0;i<n;i++){
		if (i != celebrity) {
			if(party[celebrity][i] || !party[i][celebrity]){
                return -1;
            }
		}
	}

	return celebrity;	
}

int main(){
    int party[n][n];

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> party[i][j];
        }
    }

    int celebrity = findCelebrity(party);

    cout << "celebrity is  "<< celebrity << endl;

    return 0;
}