#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// O(nlogn)

vector<int> kthSmallLarge1(vector<int> &arr, int n, int k)
{
	sort(arr.begin(), arr.end());
	return {arr[k-1],arr[n-k]};
}

#include <queue>
// TC - O(n*logk), SC - O(k)
vector<int> kthSmallLarge2(vector<int> &arr, int n, int k)
{
	priority_queue<int> maxheap;
	priority_queue<int,vector<int>,greater<int>> minheap;

	for(int i = 0;i<n;i++){
		if(maxheap.size() > k) maxheap.pop();
		if(minheap.size() > k) minheap.pop();

		maxheap.push(arr[i]);
		minheap.push(arr[i]);
 	}

	if(maxheap.size() > k) maxheap.pop();
	if(minheap.size() > k) minheap.pop();

	return { maxheap.top(), minheap.top() };
}

int main(){
    vector<int> arr = {1, 9, 8, 10, 5};

    int k = 2;
    vector<int> ans = kthSmallLarge2(arr, arr.size(), k);
    cout << ans[0] << " " << ans[1] << endl;
}