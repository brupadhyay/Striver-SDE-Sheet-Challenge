/*
BRUTE FORCE
TC - O(n^2)
SC - O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int missing = -1, repeating = -1;
	for(int i = 1;i<=n;i++){
		int cnt = 0;
		for(int j = 0;j<n;j++){
			if(arr[j] == i) cnt++;
		}
		if(cnt == 0){
			missing = i;
		} else if(cnt == 2){
			repeating = i;
		}

		if(missing != -1 && repeating != -1) break;
	}
	return {missing, repeating};	
}


/*
BETTER APPROACH - hashing
TC - O(n) + O(n)
SC - O(n)
*/


pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int missing = -1, repeating = -1;
	int freq[n + 1] = {0};

	for(int i = 0;i<n;i++){
		freq[arr[i]]++;
	}

	for(int i = 1;i<=n;i++){
		if(freq[i] == 0){
			missing = i;
		} else if(freq[i] == 2){
			repeating = i;
		}
	}
	
	return {missing, repeating};	
}

/*
OPTIMAL APPROACH 1
Using Arithmetic Maths
TC - O(n)
SC - O(1)

example {1, 2, 2}
(1+2+3) - (1 + 2 + 2) = x - y = S
x - y = 1
(1^2 + 3^2 + 2^2) - (1^2 + 2^2 + 2^2) = X^2-Y^2 = S^2
(x-y)(x+y) = s^2 = 5
(x+y) = 5

2x = 6, x = 3
y = 2
*/

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int missing, repeating;
	long long int sum = (n*(n+1))/2;
	long long int sumOfSquares = (n*(n+1)*(2*n+1))/6;

	for(int i = 0;i<n;i++){
		sum -= arr[i];
		sumOfSquares -= arr[i]*arr[i];
	}
	missing = ((sumOfSquares/sum) + sum)/2;
	repeating = missing - sum;
	
	return {missing, repeating};	
}


/*
OPTIMAL APPROACH 2
using xor based approach
TC - O(n)
SC - O(1)
*/

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xr = 0;

    // Step 1: xor of all elements
	for(int i = 0;i<n;i++){
		xr ^= arr[i];
		xr ^= i+1;
	}
    // Step 2: find differentiating bit position
	int number = (xr & ~(xr - 1));
	
	// two baskets
	int zero = 0;
	int one = 0;
		
	for(int i = 0;i<n;i++){
        // set group
		if(arr[i] & number){
			one ^= arr[i];
		} else {
            // unset group
			zero ^= arr[i];
		}
	}

	for(int i = 1;i<=n;i++){
        // set group
		if(i & number){
			one ^= i;
		} else {
            // unset group
			zero ^= i;
		}
	}
    // Step 4: identifying the repeating one
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(zero == arr[i]) cnt++;
	}

	if(cnt == 2) return {one, zero};
	return {zero, one};
}



int main() {
    vector<int> arr = {3,1,2,5,4,6,7,5};
    int n = arr.size();

    pair<int,int> ans = missingAndRepeating(arr, n);
    cout << "Missing number is " << ans.first << "\n";
    cout << "Repeating number is " << ans.second << "\n";

    return 0;
}