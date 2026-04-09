/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*>stk;
        if(!head)return nullptr;
        stk.push(head);
        Node*prev=nullptr;
        while(!stk.empty()){
            Node*curr=stk.top();
            stk.pop();
            if(prev){
                prev->next=curr;
                curr->prev=prev;
            }
            if(curr->next){
                stk.push(curr->next);
            }
            if(curr->child){
                stk.push(curr->child);
                curr->child=nullptr;
            }
            prev=curr;
        }
        return head;
    }
};