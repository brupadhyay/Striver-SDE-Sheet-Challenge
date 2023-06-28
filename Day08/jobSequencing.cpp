/*Job Sequencing Problem
Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.*/
 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

/*
Time Complexity: O(N log N) + O(N*M).

* O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

Space Complexity: 

* O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.
*/
class Solution 
{
    public:
    bool static comparison(struct Job a, Job b){
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comparison);
        
        int maxi = 0;
        for(int i = 0;i<n;i++){
            maxi = max(maxi, arr[i].dead);
        }
        
        int slot[maxi + 1];
        for(int i = 1;i<maxi+1;i++){
            slot[i] = -1;
        }
        
        int countJobs = 0, maxProfit = 0;
        for(int i = 0;i<n;i++){
            int deadline = arr[i].dead;
            
            for(int j = deadline; j>0; j--){
                if(slot[j] == -1){
                    slot[j] = arr[i].id;
                    maxProfit += arr[i].profit;
                    countJobs++;
                    break;
                }
            }
        }
        // if asked to print job sequence
        cout << "the jobs sequence is ";
        for(int i = 1;i<=maxi;i++){
            if(slot[i] != -1) cout << slot[i] << " ";
        }
        cout << "\n";
        return {countJobs, maxProfit};        
    } 
};

int main() 
{ 
    int n = 4;
    Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

    Solution ob;
    vector<int> ans = ob.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;

	return 0; 
}

