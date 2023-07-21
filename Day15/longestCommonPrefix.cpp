/**
 * Using map for storing count along with prefixes
 * TC - O(n*k) { where k is avg length of strings and n is size of arr }
 * SC - O(prefix) { no.of prefixes generated will be present in map }
*/
string longestCommonPrefix(vector<string> &arr, int n){
    map<string,int> prefixCountMap;
    for(int i = 0;i<n;i++){
        string prefix;
        string str = arr[i];
        for(int j = 0;j<str.size();j++){
            prefix += str[j];
            prefixCountMap[prefix]++;
        }
    }
    string ans = "";
    for(auto it: prefixCountMap){
        if(it.second >= n){
            ans = it.first;
        }
    }
    return ans;
}


/**
 * BETTER APPROACH 
 * for each character check if its present in all the strings then and 
 * then populate it to answer
 * TC - O(k*n) { k is size of first string and n is size of arr }
 * SC - O(1) { answer is used to store the answer }
*/
string longestCommonPrefix(vector<string> &arr, int n){
    string ans = "";
    for(int i = 0;i<arr[0].size();i++){
        char ch = arr[0][i];
        bool isSame = true;
        for(int j = 1;j<n;j++){
            if(ch != arr[j][i]){
                isSame = false;
                break;
            }
        }
        if(isSame == false) break;
        ans += ch;
    }
    return ans;
}


