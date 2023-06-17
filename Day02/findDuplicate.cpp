/*
BRUTE FORCE 
- check if some number is repeated
TC - O(n^2)
SC - O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findDuplicate(vector<int> &arr, int n){
	int duplicate = -1;
	for(int i = 0;i<n-1;i++){
		int assumedDuplicateNumber = arr[i];
		for(int j = i+1;j<n;j++){
			if(arr[j] == assumedDuplicateNumber){
				duplicate = assumedDuplicateNumber;
				break;
			}
		}
	}
	return duplicate;
}

/*
GOOD APPROACH
sorting and checking adjacent element
TC - O(nlogn) + O(n)
SC - O(1)
*/
int findDuplicate(vector<int> &arr, int n){
	int duplicate = -1;
	sort(begin(arr), end(arr));

    for(int i = 0;i<n-1;i++){
        if(arr[i] == arr[i+1]){
            duplicate = arr[i];
            break;
        }
    }

	return duplicate;
}

/*
BETTER APPROACH - hashing(frequency array)
TC - O(n)
SC - O(1)
*/

int findDuplicate(vector<int> &arr, int n){
	int freq[n] = {0};
	int duplicate = -1;

	for(int i = 0;i<n;i++){
		if(freq[arr[i]] == 0){
            freq[arr[i]]++;
        } else {
            duplicate = arr[i];
            break;
        }
	}

	return duplicate;
}

/*
OPTIMAL APPROACH
Linked List Cycle Method
TC - O(n)
SC - O(1)
*/

int findDuplicate(vector<int> &arr, int n){
	int slow = arr[0], fast = arr[0];

	do {
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while(slow != fast);

	slow = arr[0];
	while(slow != fast){
		slow = arr[slow];
		fast = arr[fast];
	}

	return slow;
}


int main() {
    vector<int> arr({1,3,4,2,2});
    cout << "Duplicate Number is "<< findDuplicate(arr, 5) << endl;

    return 0;
}

