#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A person can only work on a single activity at a time. The start time of one activity can coincide with the end time of another.

/*
TC - O(nlogn){ for sorting } + O(n) { iterating for calculating answer }
SC - O(n) { making a vector of pairs }
*/


bool static cmp(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}
int maximumActivities(vector<int> &start, vector<int> &finish) {

    vector<pair<int,int>> meet;
    int n = start.size();
    for(int i = 0;i<n;i++){
        meet.push_back({finish[i], start[i]});
    }

    sort(meet.begin(), meet.end(), cmp);

    int maxi = 1;
    int prev_finishtime = meet[0].first;

    for(int i = 1;i<n;i++){
        if(meet[i].second >=  prev_finishtime){
            prev_finishtime = meet[i].first;
            maxi++;
        }
    }
    return maxi;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> start(n);
        for(int i = 0;i<n;i++){
            int time;
            cin >> time;
            start[i] = time;
        }
        vector<int> finish(n);
        for(int i = 0;i<n;i++){
            int time;
            cin >> time;
            finish[i] = time;
        }
        
        cout << "maximum activities that are possible is "<< maximumActivities(start, finish) << endl;
    }
}