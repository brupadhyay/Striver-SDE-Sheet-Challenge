/**
 * BRUTE FORCE
 * TC - O(n x n) { for generating substrings } 
 * + O(klogk) { where k is no.of substrings}
 * + O(k) { for finding longest palindrome }
 * SC - O(k) { for storing all substrings }
*/

bool sizeComparator(string &a, string &b){
    return a.size() < b.size();
}

bool isPalindrome(string s){
    int i = 0, j = s.size()-1;
    while(i<j){
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

string longestPalinSubstring(string str) {
    vector<string> vs;
    int n = str.length();
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            vs.push_back(str.substr(i, j - i + 1));
        }
    }

    sort(vs.begin(), vs.end(), sizeComparator);
    for(int i = vs.size() - 1; i>=0; i--){
        if(isPalindrome(vs[i])){
            return vs[i];
        }
    }
    return "";
}

/**
 * OPTIMUM APPROACH
 * TC - O(n x n) { worst case  eg - "aaaa" }
 * SC - O(1)
*/

string longestPalindrome(string s) {
    int n = s.size(), st = 0, end = 0;
    for(int i = 0;i<n;i++){
        int left = i - 1, right = i + 1;
        while(left >= 0 && s[i] == s[left]){
            left--;
        }

        while(right < n && s[i] == s[right]){
            right++;
        }

        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }

        int len = right - left - 1;
        if(len > end){
            st = left + 1;
            end = len;
        }
    }
    return s.substr(st, end);
}