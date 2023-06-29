/*Time Complexity: O(2^n * k) where t is the target, k is the average length

Reason: Assume if you were allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^t different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

// ? Why not (2^n) but (2^t) (where n is the size of an array)?
// * Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

Space Complexity: O(k*x), k is the average length and x is the no. of combinations
*/
#include <bits/stdc++.h>
using namespace std;

void findKSubsets(int index, vector<int> &arr, int n, int k, int sum, vector<int> &temp,
vector<vector<int>> &ans){
    
    // if index out of bound meaning we found one of our subset
    if(index >= n){
        if(sum == k){
            ans.push_back(temp);
        }
        return;
    }

    // pick
    temp.push_back(arr[index]);
    sum += arr[index];
    findKSubsets(index + 1, arr, n, k, sum, temp, ans);
    // non pick
    temp.pop_back();
    sum -= arr[index];
    findKSubsets(index + 1, arr, n, k, sum, temp, ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> temp;
    vector<vector<int>> ans;
    findKSubsets(0, arr, n, k, 0, temp, ans);
    return ans;
}

int main() {
  vector < int > v = {5, -2, 0, -5, 2};
  int target = 0;

  vector < vector < int >> ans = findSubsetsThatSumToK(v, v.size(), target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}