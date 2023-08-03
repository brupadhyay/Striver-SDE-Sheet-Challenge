class LRUCache {

    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;

        node(int key, int val){
            this -> key = key;
            this -> val = val;
        }
    };
    
public:
    int maxcapacity;
    node* head = new node(-1,-1);
    node *tail = new node(-1,-1);
    unordered_map<int, node*> mpp;

    LRUCache(int capacity) {
        maxcapacity = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(node* toadd){
        node* temp = head -> next;
        toadd -> next = temp;
        toadd -> prev = head;
        head -> next = toadd;
        temp -> prev = toadd;
    }

    void deleteNode(node* todelete){
        node* deletenext = todelete -> next;
        node* deleteprev = todelete -> prev;
        deleteprev -> next = deletenext;
        deletenext -> prev = deleteprev;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            node* curr = mpp[key];
            mpp.erase(key);
            deleteNode(curr);
            addNode(curr);
            mpp[key] = head -> next;
            return curr -> val;
        }   
        return -1;     
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            node* exist = mpp[key];
            mpp.erase(key);
            deleteNode(exist);
        }
        // size is same then LRU erased
        if(maxcapacity == mpp.size()){
            mpp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        addNode(new node(key, value));
        mpp[key] = head -> next;
    }
};
