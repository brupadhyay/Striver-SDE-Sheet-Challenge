/**
 * Using BFS traversal and hashmap
 * TC - O(V + 2E) 
 * SC - O(V) { for queue data structure } + 
 * O(V) { since a map is used to store the graph nodes which can grow upto V. } 
 * ~ O(V)
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        map<Node*, Node*> mpp;
        queue<Node*> q;
        q.push(node);
        Node *src = new Node(node -> val);
        mpp[node] = src;

        while(!q.empty()){
            Node* vertex = q.front();
            q.pop();

            for(auto adjNode: vertex -> neighbors){
                // if cloneNode neighbors not visited
                // create one clone
                if(mpp.find(adjNode) == mpp.end()){
                    Node* clonedNode = new Node(adjNode -> val);
                    mpp[adjNode] = clonedNode;
                    q.push(adjNode);
                }                 
                // push the neighbours into the vector
                mpp[vertex] -> neighbors.push_back(mpp[adjNode]);
            }
        }        

        return mpp[node];
    }
};