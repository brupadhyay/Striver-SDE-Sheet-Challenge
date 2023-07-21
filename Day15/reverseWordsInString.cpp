/** using extra space
 * TC - O(N) { length of string }
 * SC - O(N) { stack and answer }
*/

string reverseString1(string &str){
	int n = str.length();
	string ans = "";
	string temp = "";
	stack<string> stk;
	for(int i = 0;i<n;i++){
		if(str[i] != ' ') temp += str[i];
		if(str[i] == ' ' && temp.size() > 0){
			stk.push(temp);
			temp = "";
		}
	}
	if(temp.size()) stk.push(temp);
	while(stk.size() > 1){
		ans += stk.top() + " ";
		stk.pop();
	}
	ans += stk.top();
	return ans;;
}


/**
 * OPTIMAL SOLUTION
 * TC - O(N)
 * SC - O(1) 
*/

string reverseString2(string &str){
	int n = str.length();
	string ans = "";
	string temp = "";
	for(int i = 0;i<n;i++){
		if(str[i] != ' ') temp = temp + str[i];
		if(str[i] == ' ' && temp.size() > 0){
			ans = temp + ' ' + ans;
			temp = "";
		}
	}	
	if(ans.back() == ' '){
		if(temp.size() > 0) ans = temp + ' ' + ans;
		ans.pop_back();
	}
	return ans;
}