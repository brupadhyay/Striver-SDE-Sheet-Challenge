/*Fractional Knapsack Problem : Greedy Approach
Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.*/


/*
* Time Complexity - O(NlogN + N) { nlogn for sorting and n for iterating and calculating our answer}
* Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    bool static comp(Item a, Item b){
        double val1 = (double)a.value/(double)a.weight;
        double val2 = (double)b.value/(double)b.weight;
        return val1 > val2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // sorting according to value/weight in descending order
        sort(arr, arr + n, comp);
        
        double ans = 0;
        int currWeight = 0;
        for(int i = 0;i<n;i++){
            if(currWeight + arr[i].weight <= W){
                currWeight += arr[i].weight;
                ans += arr[i].value;
            } else {
                int remainingWeight = W - currWeight;
                ans += (remainingWeight)*((double)arr[i].value/(double)arr[i].weight);
                break;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int n = 3, weight = 50;
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2)  << fixed << ans;
    return 0;
}