#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


/*
BRUTE FORCE -  TC - O(n^3) SC - O(2*(no. of triplets)) 
*/
vector<vector<int>> findTriplets1(vector<int>arr, int n, int K) {
	set<vector<int>> st;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			for(int k = j+1;k<n;k++){
				int sum = arr[i] + arr[j];
				sum += arr[k];
				if(sum == K){
					vector<int> temp = {arr[i], arr[j], arr[k]};
					sort(temp.begin(), temp.end());
					st.insert(temp);
				}
			}
		}
	}
	vector<vector<int>> ans(st.begin(), st.end());
	return ans;
}

/*
BETTER APPROACH - using hashset for lookup operations and eliminating third loop
TC - O(n^2logm) where m is size of hashset used
SC - O(2*(no.of triplets))
*/

vector<vector<int>> findTriplets2(vector<int>arr, int n, int K) {
	set<vector<int>> st;
	for(int i = 0;i<n;i++){
		set<int> hashset;
		for(int j = i+1;j<n;j++){

			int sum = arr[i] + arr[j];
			int newTarget = K - sum;

            // find - takes log(m) for set
			if(hashset.find(newTarget) != hashset.end()){
				vector<int> temp = {arr[i], arr[j], newTarget};
				sort(begin(temp), end(temp));
				st.insert(temp);
			}

			hashset.insert(arr[j]);
		}
	}
	vector<vector<int>> ans(st.begin(), st.end());
	return ans;
}


/*OPTIMIZED APPROACH - using sorting and skipping duplicates
TC - O(n^2)
SC - O(3*k) where k is no.of triplets
*/

vector<vector<int>> findTriplets3(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for(int i = 0;i<n;i++){
		if(i > 0 && arr[i] == arr[i-1]) continue;

		int j = i+1, k = n-1;
		while(j < k){
			int sum = arr[j] + arr[k];
			int target = K - arr[i];

			if(sum == target){
				vector<int> temp = {arr[i], arr[j], arr[k]};
				ans.push_back(temp);

				j++;
				k--;

				while(j < k && arr[j] == arr[j-1]) j++;
				while(j < k && arr[k] == arr[k+1]) k--;

			} else if(sum > target){
				k--;
			} else {
				j++;
			}
		}
	}
	return ans;
}

int main() {
  vector < int > arr { -1, 0, 1, 2, -1, -4};
  vector < vector < int >> ans;
  ans = findTriplets3(arr, arr.size(), 0);
  cout << "The triplets are as follows: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}