#include <bits/stdc++.h>
using namespace std;

/**
 * BRUTE FORCE - try out from minimum to maximum possible distance
 * TC - O(nlogn) + O(n*m) where m is maximum distance till we check, and
 * for each distance we try to populate cows at stall
 * SC - O(1)
*/

int aggressiveCows1(vector<int> &stalls, int k){
    int minDist = 1;
    sort(stalls.begin(), stalls.end());

    int maxPossible = 0;
    
    int n = stalls.size();
    while(true){
        int cows = 1;
        int lastPlaced = stalls[0];
        for(int i = 1;i<n;i++){
            if(stalls[i] - lastPlaced >= minDist){
                lastPlaced = stalls[i];
                cows++;
            }
        }
        if(cows < k) break;
        maxPossible = max(maxPossible, minDist);
        minDist++;
    }
    return maxPossible;
}

/**
 * OPTIMAL APPROACH - using binary search { bcz as the distance increases
 *  we are seeing a gradual decrease in placement of cows } 
 * maximum distance possible is final stall - first stall when array is sorted
 * minimum is 1
 * TC - O(nlogn) + O(n*logm) { For binary search in a space of M, O(log(M))  
 * and for each search, we iterate over max N stalls to check. O(N). }
 * SC - O(1)
*/


bool isPossible(int mid, vector<int> &stalls, int k){
    int lastPlaced = stalls[0];
    int cows = 1;
    
    for(int i = 1;i<stalls.size();i++){
        if(stalls[i] - lastPlaced >= mid){
            cows++;
            lastPlaced = stalls[i];
        }
    }
    return cows >= k;
}

int aggressiveCows2(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];

    while(low <= high){
        int mid = (low + high) >> 1;
        if (isPossible(mid, stalls, k)) {
          low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    vector<int> stalls = {1,2,8,4,9};
    int k = 3;

    cout << "maximum possible distance is "<< aggressiveCows2(stalls, k);
    return 0;
}