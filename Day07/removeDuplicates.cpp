/*Remove Duplicates in-place from Sorted Array*/

/*
BRUTE FORCE - thinking of a data structure which stores unique elements
TC - O(nlogn) + O(n) where n is size of array
SC - O(n) size for hashset
*/

#include <iostream>
#include <set>
using namespace std;

int removeDuplicates1(int arr[], int n) {
	set<int> st;
	for(int i = 0;i<n;i++){
        // insertion takes O(logn) where n is size of set
        // why log(n) because it keeps them sorted in increasing order
		st.insert(arr[i]);
	}
	int i = 0;
	for(int x: st){
		arr[i++] = x;
	}
	return st.size();
}

/*
OPTIMAL SOLUTION - Two pointers
Intuition: We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don’t get a number arr[j] which is different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j]. 
TC - O(n)
SC - O(1)
*/

int removeDuplicates2(int arr[], int n) {
	int i = 0;
	for(int j = 1;j<n;j++){
		if(arr[i] != arr[j]){
			i++;
			arr[i] = arr[j];
		}
	}
    // return size till modified array
	return i + 1;
}

int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);

  int k = removeDuplicates2(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}