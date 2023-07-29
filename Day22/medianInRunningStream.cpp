#include <queue>
int signum(int a, int b){
	if(a == b) return 0;
	else if(a > b) return 1;
	return -1;
}

int callMedian(int val, priority_queue<int> &maxq,
priority_queue<int, vector<int>, greater<int>> &minq){
	int a = maxq.size();
	int b = minq.size();
	switch(signum(a, b)){
		case 0: if(!maxq.empty() && val < minq.top()){
			maxq.push(val);
			return maxq.top();
		} else {
			minq.push(val);
			return minq.top();
		}

		case 1: if(val > maxq.top()){
			minq.push(val);
			return (minq.top() + maxq.top())/2;
		} else {
			minq.push(maxq.top());
			maxq.pop();
			maxq.push(val);
			return (minq.top() + maxq.top())/2;
		}

		case -1: if(val < minq.top()){
			maxq.push(val);
			return (minq.top() + maxq.top())/2;
		} else {
			maxq.push(minq.top());
			minq.pop();
			minq.push(val);
			return (minq.top() + maxq.top())/2;
		}
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;

	vector<int> median;
	for(int i = 0;i<n;i++){
		int currMedian = callMedian(arr[i], maxq, minq);
		median.push_back(currMedian);
	}
	return median;
}
