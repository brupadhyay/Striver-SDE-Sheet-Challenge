#include <iostream>
#include <vector>
using namespace std;

class minheap{
    public:
    vector<int> heap;

    minheap(){
        heap.resize(0);
    }

    void insertInMinHeap(int value){
        // add the element
        heap.push_back(value);

        int index = heap.size() - 1;

        while(index > 0){
            int parentIndex = (index-1)/2;

            if(heap[parentIndex] > heap[index]){
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                return;
            }
        }
    }

    void deleteInMinHeap(){
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

            int smallest = i;
            if(leftChild < size && heap[leftChild] < heap[i]){
                smallest = leftChild;
            }
            if(rightChild < size && heap[rightChild] < heap[smallest]){
                smallest = rightChild;
            }

            if(smallest != i){
                swap(heap[smallest], heap[i]);  
                i = smallest;
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

int main() {

    minheap obj;

    obj.insertInMinHeap(60);
    obj.insertInMinHeap(50);
    obj.insertInMinHeap(54);
    obj.insertInMinHeap(53);
    obj.insertInMinHeap(70);

    // obj.deleteInMinHeap();

    obj.printHeap();

    // minimum element
    if(obj.heap.size() != 0){
        cout << "maximum is "<< obj.heap[0] << endl;
    }
    return 0;
}