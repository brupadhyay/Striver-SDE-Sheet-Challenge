// BRUTE APPROACH
// generate all possible permutations and check for the matching permutation,
// the next permutation to that is our answer
// TC - O(n x n!)

// BETTER APPROACH
// TC - O(n) in the worst case

#include <bits/stdc++.h> 
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int arr[n] = {0};
    for(int i = 0;i<n;i++){
        arr[i] = permutation[i];
    }
    next_permutation(arr, arr + n);
    vector<int> ans;
    for(int i = 0;i<n;i++){
        ans.push_back(arr[i]);
    }
    return ans;
}

// OPTIMAL SOLUTION
// TC - 

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int breakpoint = -1;
    for(int i = n-2;i>=0;i--){
        // 2 3 1
        // breakpoint - index = 0
        if(permutation[i] < permutation[i+1]){
            breakpoint = i;
            break;
        }
    }

    if(breakpoint == -1){
        // meaning it's like [3, 2, 1] so we return {1, 2, 3}
        reverse(begin(permutation), end(permutation));
        return permutation;
    }

    for(int i = n-1;i>breakpoint;i--){
        if(permutation[i] > permutation[breakpoint]){
            // 2 3 1
            // now it becomes 3 2 1
            // so it's a next permutation because at index 0 we have 3 (3 > 2)
            swap(permutation[i], permutation[breakpoint]);
            break;
        }
    }
    
    // to make permutation as close as possible
    reverse(begin(permutation) + breakpoint + 1, end(permutation));
    return permutation;    
}


