#include <bits/stdc++.h>
using namespace std;

/*
TC - 2^n { where n is size of string s } + O(klogk) { mapping wordDict }
SC - O(k) { word dictionary } + O(n) { stack space }
*/

class Solution {
    bool solve(int index, string s, map<string, bool> &mpp){
        if(index >= s.size()){
            return true;
        }
        for(int i = index;i<s.size();i++){
            string sub = s.substr(index, i - index + 1);
            if(mpp.find(sub) != mpp.end()){
                if(solve(i + 1, s, mpp) == true){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> mpp;
        for(auto it: wordDict){
            mpp[it] = true;
        }
        return solve(0, s, mpp);
    }
};

int main(){
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    Solution obj;
    if(obj.wordBreak(s, wordDict)){
        cout << "possible to break";
    } else cout << "not possible";

    return 0;
}