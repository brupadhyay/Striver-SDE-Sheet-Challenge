/*
BRUTE FORCE - (recursive) using visited array and data structure to store
TC - O(N!*N) { N! for permutations and O(N) for inserting permutations into the data structure }
SC - O(N) { as we use visited array and temporary vector for storing permutations}
*/
#include <bits/stdc++.h>
using namespace std;

void permutationsHelper(string &s, string &temp, int freq[], vector<string> &ans){
    if(temp.size() == s.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = 0;i<s.size();i++){
        if(!freq[i]){
            temp.push_back(s[i]);
            freq[i] = 1;
            permutationsHelper(s, temp, freq, ans);
            freq[i] = 0;
            temp.pop_back();
        }
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    int freq[s.size()];
    for(int i = 0;i<s.size();i++){
        freq[i] = 0;
    }
    string temp = "";
    permutationsHelper(s, temp, freq, ans);
    return ans;
}

/*
OPTIMAL APPROACH - (backtracking) using swap logic
TC - O(N!*N) 
SC - O(1) { we swap using given array and we are using a data structure to store our answer and not to solve the problem }
*/

void permutationsHelper(int ind, string &s, vector<string> &ans){
    if(ind >= s.size()){
        ans.push_back(s);
        return;
    }

    for(int i = ind;i<s.size();i++){
        swap(s[i], s[ind]);
        permutationsHelper(ind + 1, s, ans);
        swap(s[i], s[ind]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    permutationsHelper(0, s, ans);
    return ans;
}
