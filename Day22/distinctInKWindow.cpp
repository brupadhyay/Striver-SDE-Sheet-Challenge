/**
 * Using map
 * TC - O(N*logK)
 * SC - O(K)
*/
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> distinctCount;
    map<int,int> mpp;

    for(int i = 0;i<arr.size();i++){
        mpp[arr[i]]++;

        if(i >= k){
            if(--mpp[arr[i-k]] == 0){
                mpp.erase(arr[i-k]);
            }
        }
        
        if(i >= k-1) distinctCount.push_back(mpp.size());
    }
    return distinctCount;	
}