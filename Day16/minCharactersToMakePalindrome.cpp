/*Time complexity: O(n^2)
Auxiliary Space: O(1) */

bool isPalindrome(string s){
	for(int i = 0;i<s.length()/2;i++){
		if(s[i] != s[s.length() - i - 1]) return false;
	}
	return true;
}

int minCharsforPalindrome(string s) {
	int cnt = 0;
	while(s.length() > 0){
		if(isPalindrome(s)){
			break;
		} else {
			cnt++;
			s.erase(s.begin() + s.length() - 1);
		}
	}
	return cnt;
}


/**
 * TC - O(n)
 * SC - O(1)
*/

int minCharsforPalindrome(string str) {
	int res = 0;
	int n = str.length();
	int l = 0, r = n-1;

	while(l < r){
		if(str[l] == str[r]){
			l++;
			r--;
		} else {
			res++;
			l = 0;
			r = n - res - 1;
		}
	}
	return res;
}
