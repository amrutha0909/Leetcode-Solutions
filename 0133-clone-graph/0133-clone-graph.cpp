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
        Node*cloneRoot=new Node(node->val);
        unordered_map<Node*,Node*>mpp;
        mpp[node]=cloneRoot;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            auto curr=q.front();q.pop();
            for(auto neigh:curr->neighbors){
                if(mpp.find(neigh)==mpp.end()){
                    Node*neighClone=new Node(neigh->val);
                    mpp[neigh]=neighClone;
                    q.push(neigh);
                }
                mpp[curr]->neighbors.push_back(mpp[neigh]);
            }
        }
        return cloneRoot;
    }
};