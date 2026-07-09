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
        if(!node)return nullptr;
        unordered_map<Node*,Node*>mpp;
        mpp[node]=new Node(node->val);  
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
        return mpp[node];
    }
};