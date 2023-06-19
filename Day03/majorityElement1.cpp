/*
NAIVE APPROACH
TC - O(N^2)
SC - O(1)
- FOR EVERY ELEMENT WE TAKE OUT THE COUNT IF IT SATISFIES > FLOOR(N/2) WE RETURN IT
*/

/*
BETTER APPROACH - using hashing 
if it's a frequency array then TC will be O(2n)
but for ordered map complexity of insertion is O(logn)
but for unordered map complexity of insertion is O(1) { best and average case}
and O(n) { for worst case}
TC - O(n*logn) + O(n)
SC - O(n)
*/

/*
OPTIMAL APPROACH - Moore's Voting Algorithm
- intuition is to count majority occurence and if it's a different element we decrease
TC - O(n) { for algo } + O(n) { for checking if candidate occurs for more than n/2 times}
SC - O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int> &arr, int n) {
	int ele = 0, cnt = 0;
	for(int i = 0;i<n;i++){
		if(cnt == 0) {
			ele = arr[i];
		}

		if(arr[i] == ele){
			cnt++;
		} else {
			cnt--;
		}
	}
	cnt = 0;
	for(int i = 0;i<n;i++){
		if(ele == arr[i]) {
			cnt++;
		}
	}
	
	return cnt > n/2 ? ele : -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = findMajorityElement(arr, arr.size());
    cout << "The majority element is: " << ans << endl;
    return 0;
}