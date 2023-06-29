/*BRUTE FORCE - to store all subsets in an set and return
Time Complexity: O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. After this, we have to convert the set of combinations back into a list of list /vector of vectors which takes more time.

Space Complexity:  O(2^n * k) to store every subset of average length k. Since we are initially using a set to store the answer another O(2^n *k) is also used.
*/


/*OPTIMAL SOLUTION - 
Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
*/

#include <bits/stdc++.h>
using namespace std;
void printAns(vector < vector < int >> & ans) {
  cout << "The unique subsets are " << endl;
  cout << "[ ";
  for (int i = 0; i < ans.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "]";
  }
  cout << " ]";
}

class Solution {
  public:
    void subsetHelper1(int ind, vector<int> &arr, int n, set<vector<int>> &st, vector<int> subset){
        if(ind == n){
            sort(subset.begin(), subset.end());
            st.insert(subset);
            return;
        }

        subset.push_back(arr[ind]);
        subsetHelper1(ind + 1, arr, n, st, subset);
        subset.pop_back();
        subsetHelper1(ind + 1, arr, n, st, subset);   
    }
    void subsetHelper2(int ind, vector<int> &arr, int n, vector<int> subset,
    vector<vector<int>> &ans){
        ans.push_back(subset);

        for(int i = ind; i < n; i++){
            // if for the first time, we consider it and afterwards we neglect duplicates
            if(i > ind && arr[i] == arr[i-1]) continue;
            // picked the element
            subset.push_back(arr[i]);
            
            subsetHelper2(i + 1, arr, n, subset, ans);
            
            // backtrack
            subset.pop_back();
        }
    }
    vector < vector < int >> subsetsWithDup(vector < int > &arr) {
        set<vector<int>> st;
        vector<int> subset;
        vector<vector<int>> ans;
        // APPROACH 1
        // subsetHelper1(0, arr, arr.size(), st, subset);
        // for(auto it = st.begin(); it != st.end(); it++){
        //     ans.push_back(*it);
        // }

        // APPROACH 2
        // sorting for having duplicates consecutive
        sort(arr.begin(), arr.end());
        subsetHelper2(0, arr, arr.size(), subset, ans);
        
        return ans;
    }
};



int main() {
  Solution obj;
  vector < int > arr = {1, 2, 2, 2, 3};
  vector < vector < int >> ans = obj.subsetsWithDup(arr);
  printAns(ans);
  return 0;
}