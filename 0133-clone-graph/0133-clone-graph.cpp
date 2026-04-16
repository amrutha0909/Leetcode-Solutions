/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //create a map that stores original and clone nodes
        //store the root and its clone in the map
        //push the root in a queue to perform bfs on the adjacent nodes
        //if clone of neighbour node does not exist in the map->create a new clone node 
        //mpp[node]->neighbors.push_back(mpp[neigh]) => mpp[neigh] is the clone of neigh, so we push it into the clone neighbors vector mpp[node]->neighbors
        if(!node)return nullptr;
        unordered_map<Node*,Node*>mpp;
        Node*cloneRoot=new Node(node->val);
        mpp[node]=cloneRoot;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto neigh:node->neighbors){
                if(mpp.find(neigh)==mpp.end()){
                    Node*cloneNeigh=new Node(neigh->val);
                    mpp[neigh]=cloneNeigh;
                    q.push(neigh);
                }
                mpp[node]->neighbors.push_back(mpp[neigh]);
            }
            
        }
        return cloneRoot;
    }
};