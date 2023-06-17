// BRUTE FORCE
// Time Complexity - O(n^2)
// SC - O(1)


#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
    }

    return maxPro;
}


/*
Optimal Approach - 
Instead of two loops
we will maintain the lowest price till the date and try to find the maximum profit by selling by maintaining a maxprofit variable
TC - O(n)
SC - O(1)
*/

int maxProfit(vector<int> &prices){
    int n = prices.size();
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int i = 0;i<n;i++){
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
}


int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}


