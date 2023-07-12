#include "queue"
#include "iostream"
using namespace std;

/**
 * TC - O(nlogn) for every element we either push element in either of the heaps
 * and find median
 * SC - O(n) + O(n) ~ O(2n) { for two heaps maintained }
*/


int signum(int a, int b){
    if(a == b) return 0;
    return a > b ? 1 : -1;
}

void call_median(priority_queue<int> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap, int ele, int& median){
    switch(signum(maxheap.size(), minheap.size())){
        case 0: if(ele > median){
            minheap.push(ele);
            median = minheap.top();

        } else {
            maxheap.push(ele);
            median = maxheap.top();
        }
        break;

        case 1: if(ele > median){
            minheap.push(ele);
            median = (maxheap.top() + minheap.top())/2;
        } else {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(ele);
            median = (maxheap.top() + minheap.top())/2;
        }
        break;

        case -1: if(ele > median){
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(ele);
            median = (maxheap.top() + minheap.top())/2;
        } else {
            maxheap.push(ele);
            median = (maxheap.top() + minheap.top())/2;
        }
        break;
    }
}

void findMedian(int *arr, int n)
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    int median = 0;
    for(int i = 0;i<n;i++){
        int ele = arr[i];
        call_median(maxheap, minheap, ele, median);
        cout << median << " ";
    }
}

int main(){
    int arr[6] = {6,2,1,3,7,5};
    int n = 6;
    cout << "the median at each interval is ";
    findMedian(arr, n);

    return 0;
}