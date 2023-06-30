#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:O(2^n*k)

Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

Space Complexity:O(k*x)

Reason: if we have x combinations then space will be x*k where k is the average length of the combination.*/

void findCombinations(int ind, vector<int> arr, int n, int target, vector<int> subset, 
vector<vector<int>> &ans){
	if(target == 0){
		ans.push_back(subset);
		return;
	}

	for(int i = ind;i<n;i++){
        // skipping duplicate other than first occurence
		if(i != ind && arr[i] == arr[i-1]) continue;
        // as array is sorted we break here
		if(arr[i] > target) break;
        
		// pick the element
		subset.push_back(arr[i]);
		findCombinations(i + 1, arr, n, target - arr[i], subset, ans);
		// non pick
		subset.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	vector<vector<int>> ans;
	vector<int> subset;
	sort(arr.begin(), arr.end());
	findCombinations(0, arr, n, target, subset, ans);
	return ans;
}

int main() {
  vector<int> v{10,1,2,7,6,1,5};
  vector < vector < int >> comb = combinationSum2(v, v.size(), 8);
  cout << "[ ";
  for (int i = 0; i < comb.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << "]";
  }
  cout << " ]";
}