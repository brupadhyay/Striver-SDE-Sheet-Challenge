#include <iostream>
#include <vector>
using namespace std;

class maxheap{
    public:
    vector<int> heap;

    maxheap(){
        heap.resize(0);
    }
    // O(logn)
    void insertInMaxHeap(int value){
        // add the element
        heap.push_back(value);

        int index = heap.size() - 1;

        while(index > 0){
            int parentIndex = (index-1)/2;

            if(heap[parentIndex] < heap[index]){
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                return;
            }
        }
    }

    // O(logn)
    void deleteInMaxHeap(){
        // deletion from top
        int size = heap.size();
        if(size == 0) return;
        heap[0] = heap[size - 1];
        heap.pop_back();
        size--;

        int i = 0;
        while(i < size){
            int leftChild = 2*i + 1;
            int rightChild = 2*i + 2;

            int largest = i;
            // maximum from left as well as right
            if(leftChild < size && heap[leftChild] > heap[i]){
                largest = leftChild;
            }
            if(rightChild < size && heap[rightChild] > heap[largest]){
                largest = rightChild;
            }

            if(largest != i){
                swap(heap[largest], heap[i]);  
                i = largest;
            } else return;
                     
        }
    }

    void printHeap(){
        for(int i = 0; i<heap.size(); i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }

};


void heapify(int arr[], int n, int i){
    int largest = i;
    
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main() {
    
    maxheap obj;

    obj.insertInMaxHeap(60);
    obj.insertInMaxHeap(50);
    obj.insertInMaxHeap(54);
    obj.insertInMaxHeap(53);
    obj.insertInMaxHeap(70);

    obj.deleteInMaxHeap();
    obj.deleteInMaxHeap();

    obj.printHeap();

    // maximum element
    if(obj.heap.size() != 0){
        cout << "maximum is "<< obj.heap[0] << endl;
    } 

    int arr[6] = {6, 12, 7, 19, 22, 4};
    int n = 6;

    /**
     * heapify - only n/2 - 1 -> 1 nodes to be processed
     * n/2 -> n - 1 are leaf nodes
    */

    // for(int i = n/2;  i>=0; i--){
    //     heapify(arr, n, i);
    // }
    // for(int i = 0;i<n;i++){
    //     cout << arr[i] << " ";
    // }

    return 0;
}