#include<bits/stdc++.h>
using namespace std;


/*
TC - O(2^n) + O(2^nlog(2^n)) { Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)). }
SC - O(2^n) { for storing our subset sums, since 2^n subsets can be possible for an array of size n }
*/


class Solution {
  public:
    void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
    vector < int > subsetSums(vector < int > arr, int n) {
        vector < int > ans;
        subsetSumsHelper(0, arr, n, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    vector < int > arr{3,1,2};
    Solution ob;
    vector < int > ans = ob.subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout<<"The sum of each subset is "<<endl;
    for (auto sum: ans) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}