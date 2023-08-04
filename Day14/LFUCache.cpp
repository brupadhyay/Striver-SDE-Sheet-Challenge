/**
 * Node for the list
*/

struct Node{
    int key, val, cnt;
    Node* next, *prev;

    Node(int key, int val){
        this -> key = key;
        this -> val = val;
        this -> cnt = 1; // freq how many times it got updated
    }
};


// List for each frequency
// 1 - [List]
// 2 - [List]

struct List{
    int size;
    Node* head, *tail;

    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        // head <----> tail
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }

    void addFront(Node* newNode){
        Node* temp = head -> next;
        head -> next = newNode;
        newNode -> next = temp;
        temp -> prev = newNode;
        newNode -> prev = head;
        size++;
    }

    void removeNode(Node* nodeToBeDeleted){
        Node* nodeToBeDeletedNext = nodeToBeDeleted -> next;
        Node* nodeToBeDeletedPrev = nodeToBeDeleted -> prev;
        nodeToBeDeletedNext -> prev = nodeToBeDeletedPrev;
        nodeToBeDeletedPrev -> next = nodeToBeDeletedNext;
        size--; 
    }
};


class LFUCache {
    int cacheSize, minFreq;
    map<int,Node*> keyNode;
    map<int,List*> freqList;
public:


    LFUCache(int capacity) {
        cacheSize = capacity;
        minFreq = 0;
    }

    void updateFreqList(Node *curr){
        // remove the node from list
        freqList[curr -> cnt] -> removeNode(curr);
        // if the list had only one node then size would become zero and 
        // 1 == node -> cnt
        if(curr -> cnt == minFreq && freqList[curr -> cnt] -> size == 0){
            minFreq += 1; // move to freq = 2
        }
        // new list
        List* nextHighList = new List();
        if(freqList.find(curr -> cnt + 1) != freqList.end()){
            nextHighList = freqList[curr -> cnt + 1]; // if freq 2 has some list update
        }
        // node gets updated so cnt or freq ++
        curr -> cnt += 1;
        // add next to head of list
        nextHighList -> addFront(curr);
        // create key,node
        keyNode[curr -> key] = curr;
        // put list at correct freq
        freqList[curr -> cnt] = nextHighList;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* curr = keyNode[key];
            // erase from keynode
            keyNode.erase(curr -> key);
            // update the freq list
            updateFreqList(curr);
            return curr -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cacheSize == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* curr = keyNode[key];
            curr -> val = value;
            keyNode.erase(curr -> key);
            updateFreqList(curr);
        } else {
            // capacity
            if(cacheSize == keyNode.size()){
                // get list of minfreq
                List* currList = freqList[minFreq];
                // remove the LRU or LFU
                // we always move at front so LRU will be at last
                // and acc. to minFreq and only one node in list
                // so delete LRU
                keyNode.erase(currList -> tail -> prev -> key);
                currList -> removeNode(currList -> tail -> prev);
            }
            List* newList = new List(); // after deletion
            // minfreq = 1 because new node is going to be added
            minFreq = 1; // new addition
            if(freqList.find(minFreq) != freqList.end()){
                newList = freqList[minFreq]; // if freq = 1 has elements
            }
            Node* newNode = new Node(key, value);
            newList -> addFront(newNode); // add at front
            keyNode[key] = newNode; // create key, node pair
            freqList[minFreq] = newList; // update list at freq = 1
        }
    }
};
