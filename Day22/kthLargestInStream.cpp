/**
 * TC - O(n*logk)
 * SC - O(k)
*/

class Kthlargest {
    priority_queue<int,vector<int>, greater<int>> pq;
public:

    Kthlargest(int k, vector<int> &arr) {
        for(int i = 0;i<k;i++){
            pq.push(arr[i]);
        }
    }

    int add(int num) {
        if(num > pq.top()){
            pq.pop();
            pq.push(num);
        }
        return pq.top();
    }

};