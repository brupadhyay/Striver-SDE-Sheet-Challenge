Search Pattern (Rabin-Karp Algorithm)

/**
 * Using substr function
 * TC - O(n) { where n is size of text } 
 * + O(k) { since we find substring, where k is length of pattern }
 * SC - O(1) { ans is used to store the answer not to solve the problem }
*/

vector<int> stringMatch(string text, string pattern) {
	vector<int> ans;
	int patLen = pattern.size();
    int textLen = text.size();
	for(int i = 0;i<textLen;i++){

		if(text[i] == pattern[0]){

			if(i + patLen - 1 < textLen){                
				string test = text.substr(i, patLen);

				if(test == pattern){
					ans.push_back(i + 1);
				}
			}
		}
	}
	return ans;
}
