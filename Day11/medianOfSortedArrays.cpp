#include <bits/stdc++.h>
using namespace std;

// TC - O(n + m) SC - O(n + m)

double median(vector<int>& a, vector<int>& b) {
	int n = a.size(), m = b.size();
	int merged[n+m];

	int i = 0, j = 0, k = 0;
	while(i<n && j < m){
		if(a[i] <= b[j]){
			merged[k++] = a[i++];
		} else {
			merged[k++] = b[j++];
		}
	}

	while(i < n){
		merged[k++] = a[i++];
	}
	while(j < m){
		merged[k++] = b[j++];
	}

	n = n + m;

	if(n % 2 == 1){
		return merged[n/2];
	} 
	return (merged[n/2] + merged[n/2-1])/2.0;
}

// TC - O(n + m), SC - O(1)

double median(vector<int>& a, vector<int>& b) {
	int n = a.size(), m = b.size();
	int median = (n+m)/2;
	
	int prev = 0, curr = 0;
	int cnt = 0, i = 0, j = 0;
	while(cnt <= median){
		prev = curr;

		if(i < n && j < m){
			if(a[i] <= b[j]){
				curr = a[i++];
			} else {
				curr = b[j++];
			}
			cnt++;
		} else if(i < n){
			curr = a[i++];
			cnt++;
		} else {
			curr = b[j++];
			cnt++;
		}
	}
	if((n+m) % 2 == 0){
		return (prev + curr)/2.0;
	}
	
	return curr;
}

/*
OPTIMAL APPROACH - using partitions
TC - O(log(min(n,m))) { Reason – We are applying binary search on the array which has a minimum size. }
SC - O(1)
*/
double median(vector<int>& a, vector<int>& b) {
	if(a.size() > b.size()) return median(b, a);
	int n = a.size();
	int m = b.size();
	
	int low = 0, high = n;

    /*
    median position = (n + m + 1)/ 2 because if n+m is even then (n+m)/2 == (n+m+1)/2
    but for odd if n + m = 9 then (n+m+1)/2 = 5 so our algorithm will work fine
    */

	while(low <= high){
		int cut1 = (low + high) / 2;
		int cut2 = (n + m + 1) / 2 - cut1;

		int left1 = cut1 == 0 ? INT_MIN : a[cut1-1];
		int left2 = cut2 == 0 ? INT_MIN : b[cut2-1];

        // edge case a[] = {1, 3} b[] = {2, 4, 6} here in second iteration 
        // cut1 becomes equal to n so assign right1 to INT_MAX is very much imp
		int right1 = cut1 == n ? INT_MAX : a[cut1];
		int right2 = cut2 == m ? INT_MAX : b[cut2];
		
		if(left1 <= right2 && left2 <= right1){
			if((n + m) % 2 == 0){
				return (max(left1, left2) + min(right1, right2))/2.0;
			} else {
				return max(left1, left2);
			}
		} else if( left1 > right2){
			high = cut1 - 1;
		} else {
			low = cut1 + 1;
		}
	}
	return a[low];
}