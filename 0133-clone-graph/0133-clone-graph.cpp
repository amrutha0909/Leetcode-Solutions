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
        queue<Node*>q;
        unordered_map<Node*,Node*>cloneMap;
        Node*cloneRoot=new Node(node->val);
        cloneMap[node]=cloneRoot;
        q.push(node);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto neigh:curr->neighbors){
                if(cloneMap.find(neigh)==cloneMap.end()){
                    Node*neighClone=new Node(neigh->val);
                    cloneMap[neigh]=neighClone;
                    q.push(neigh);
                }
                cloneMap[curr]->neighbors.push_back(cloneMap[neigh]);
            }
        }
        return cloneRoot;
    }
};