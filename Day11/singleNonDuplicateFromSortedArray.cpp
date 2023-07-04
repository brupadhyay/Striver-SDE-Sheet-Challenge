/*
BRUTE FORCE - 
pick element and check if it's present one more time if not that is our non-duplicate answer
TC - O(N*N)
SC - O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate1(vector<int>& arr){
	int res = 0;
	for(int i = 0;i<arr.size();i++){
		bool flag = true;
		for(int j = 0;j<arr.size();j++){
			if(j != i && arr[i] == arr[j]) flag = false;
		}
		if(flag == true){
			res = arr[i];
            break;
		}
	}
	return res;
}


/*
BETTER APPROACH - using set for storing our non-duplicate element
TC - O(N*logk)
SC - O(1)
*/
#include <set>
int singleNonDuplicate2(vector<int>& arr)
{
	int res = 0;
	set<int> st;
	for(int i = 0;i<arr.size();i++){
		if(st.find(arr[i]) != st.end()){
			st.erase(arr[i]); // log(st.size())
		} else {
			st.insert(arr[i]); // log(st.size())
		}
	}
	return *(st.begin());
}


/*
BETTER APPROACH - a ^ a = 0 so all duplicates xor will be zero except our single
TC - O(N)
SC - O(1)
*/
int singleNonDuplicate3(vector<int>& arr){
	int xr = 0;
	int n = arr.size();
	for(int i = 0;i<n;i++){
		xr = xr^arr[i];
	}
	return xr;
}

/*
OPTIMAL APPROACH - using binary search
TC - O(logn)
SC - O(1)
*/
int singleNonDuplicate4(vector<int>& arr)
{
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high) >> 1;
        
        if(mid & 1){
            // odd case
            // mid == mid + 1 meaning we are in right half so shrink to left portion
            if(arr[mid] == arr[mid + 1]){
                high = mid - 1;
            } else {
                // mid is second occurence meaning we're in left half 
                // so shrink to right
                low = mid + 1;
            }
        } else {
            // mid is even and first occurence
            // we're in left half
            if(arr[mid] == arr[mid + 1]){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return arr[low];
}


int main() {
    vector<int> arr {1,1,2,3,3,4,4,5,5};
    cout<<"non-duplicate element is "<< singleNonDuplicate4(arr);

    return 0;
}