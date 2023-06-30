#include <bits/stdc++.h>
using namespace std;

// for n = 3, permutations = 3! = 6

/*
BRUTE FORCE - recursion to store all permutations and return kth permutation after sorting
TC - O(N!*N) + O(N!log(N!)) {
    The recursion takes O(N!) time because we generate every possible permutation and another O(N)  time is required to make a deep copy and store every sequence in the data structure. Also, O(N! Log N!)  time required to sort the data structure
}
SC - O(N!)
*/
void helper(int ind, string &s, int n, int &k, vector<string> &ans){

    if(ind >= n){
        ans.push_back(s);
        return;
    }

    for(int j = ind;j<n;j++){
        swap(s[ind], s[j]);
        helper(ind + 1, s, n, k, ans);
        swap(s[ind], s[j]);
    }
}

string kthPermutation1(int n, int k) {
    string s = "";
    for(int i = 1;i<=n;i++){
        s += i + '0';
    }
    vector<string> ans;
    helper(0, s, n, k, ans);
    sort(ans.begin(), ans.end());
    return ans[k-1];
}



/*
OPTIMAL APPROACH - using mathematical observation

Time Complexity: O(N) * O(N) = O(N^2)

Reason: We are placing N numbers in N positions. This will take O(N) time. For every number, we are reducing the search space by removing the element already placed in the previous step. This takes another O(N) time.

Space Complexity: O(N) 

Reason: We are storing  the numbers in a data structure(here vector)
*/

string kthPermutation2(int n, int k) {
    string ans = "";
    vector<int> nums;
    int fact = 1;
    for(int i = 1;i<=n;i++){
        fact = fact*i;
        nums.push_back(i);
    }
    k = k - 1;
    while(true){
        fact = fact / nums.size();
        ans = ans + to_string(nums[k/fact]);
        nums.erase(nums.begin() + k / fact);
        
        if(nums.size() == 0){
            break;
        }
        k = k % fact;
    }
    return ans;
}


int main() {
    int n = 4;
    int k = 17;

    cout << "the kth sequence is " << kthPermutation2(n, k) << endl;
    return 0;
}

