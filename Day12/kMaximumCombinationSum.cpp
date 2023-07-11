#include <bits/stdc++.h> 
using namespace std;

// TC - O(n*nlog(n*n)) + O(k*log(n*n))

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int> pq;

	for(int i = 0;i<n;i++){
		int sum = a[i];
		for(int j = 0;j<n;j++){
			sum += b[j];
			pq.push(sum);
			sum -= b[j];
		}
	}

	vector<int> ans;
	while(k--){
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}