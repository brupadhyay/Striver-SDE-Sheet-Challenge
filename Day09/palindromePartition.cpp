/*Problem Statement: You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.

Note: A palindrome string is a string that reads the same backward as forward.*/


/*
Time Complexity: O( (2^n) *k*(n/2) )

Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)

Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // O(N/2)
    bool isPalindrome(string s, int i , int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void findPartitions(int ind, string s, vector<string> part, vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(part);
            return;
        }


        for(int i = ind;i<s.size();i++){
            // check for palindrome
            if(isPalindrome(s, ind , i)){
                // s.substr(index, size) 
                // aabb index = 0, i = 1 ---- s.substr(0, 1 - 0 + 1) -- (0,2)
                part.push_back(s.substr(ind, i - ind + 1));
                findPartitions(i + 1, s, part, ans);
                part.pop_back(); // backtrack
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        findPartitions(0, s, part, ans);
        return ans;
    }
};

int main(){
    Solution obj;
    string s  = "aabb";
    vector<vector<string>> ans = obj.partition(s);
    cout << "the palindrome partitions are: ";
    for(int i = 0;i<ans.size(); i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    return 0;
}