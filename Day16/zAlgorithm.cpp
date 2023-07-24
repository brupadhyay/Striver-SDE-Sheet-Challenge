/**
 * TC - O(n*m)
 * SC - O(1)
*/

int zAlgorithm(string s, string p, int n, int m)
{
	int ans = 0;
	for(int i = 0;i<=n-m;i++){
		if(p[0] == s[i]){
			string sub = s.substr(i, m);
			if(sub == p) ans++;
		}
	}
	return ans;
}

/**
 * TC - O(n + m)
 * SC - O(n + m) { z array }
*/

void generateZ(string str, int z[]){
	int len = str.length();
	int L = 0, R = 0,i;
	for(i = 1;i<len;i++){
		if(i > R){
			L = R = i;

			while(R < len && str[R-L] == str[R]){
				R++;
			}
			z[i] = R-L;
			R--;
		} else {
			int k = i - L;
			if(z[k] < R - i + 1){
				z[i] = z[k];
			} else {
				L = i;
				while(R < len && str[R - L] == str[R]){
					R++;
				}
				z[i] = R - L;
				R--;
			}
		}
	}
}

int zAlgorithm(string s, string p, int n, int m)
{
	int z[n+m+1];
	s = p + '#' + s;
	generateZ(s, z);
	
	int occ = 0;
	for(int i = m+1;i<n+m+1;i++){
		if(z[i] == m) occ++;
	} 
	return occ;
}