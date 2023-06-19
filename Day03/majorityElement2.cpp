/*
observation - _ _ _ _ _ _ _ _ 
if i have 8 sized array then 8/3 is 2 so occuping more than 2, meaning atleast
3 index for each element is valid for only 2 elements, 
1 1 1 2 2 2 3 3 || 3 (out of bound)
so atmost an array can have 2 majority elements which occur more than n/3 times
*/


/*
brute force - 
-> go across the array
-> maintain a list and check if size is zero || previous pushed element is !currElement
-> and for each elements count it's frequency if its more than n/3 push
-> at any point ls.size() is 2 you break

TC - O(n^2)
SC - O(1)
*/

/*
better approach
- maintain a hashmap for counting frequency
TC - O(nlogn) is ordered map
SC - O(n)
*/

/*
extended boyer moore's voting algorithm
edge case - 2 1 1 3 1 4 5 6
- while updating candidate check if arr[i] != other candidate
- finally manual check for proving worthyness of majority
TC - O(n) + O(n)
SC - O(1)
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

int main()
{
    vector<int> arr = {2, 1, 1, 3, 1, 4, 5, 6};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}