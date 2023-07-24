#include <iostream>
using namespace std;

/**
 * Using recursion
 * TC - O(1) + O(2) + ...O(n-1) ~ O(n^2)
 * SC - O(n + m) { n for recursion depth and m for temp in each call }
*/

class Solution {
    string say(string curr, int n){
        if(n <= 0){
            return curr;
        }
        string temp;
        int l = 0, r = 0;
        while(r < curr.size()){
            while(r < curr.size() && curr[l] == curr[r]) r++;
            temp += to_string(r - l);
            temp += curr[l];
            l = r;
        }
        return say(temp, n-1);
    }
public:
    string countAndSay(int n) {
        string curr = "1";
        return say(curr, n-1);
    }
};

int main(){
    int n = 5;
    Solution obj;
    cout << "string is "<< obj.countAndSay(n);
    return 0;
}