/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare{
        bool operator()(ListNode*a,ListNode*b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,compare>pq; 
        for(ListNode*list:lists){
            if(list)pq.push(list);
        }   
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            temp->next=curr;
            if(curr->next){
                pq.push(curr->next);
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};