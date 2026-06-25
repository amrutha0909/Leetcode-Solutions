/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return nullptr;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            vector<Node*>level;
            for(int i=0;i<len;i++){
                Node*node=q.front();q.pop();
                level.push_back(node);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            for(int i=0;i<len-1;i++){
                level[i]->next=level[i+1];
            }
            level[len-1]->next=nullptr;
        }
        return root;
    }
};