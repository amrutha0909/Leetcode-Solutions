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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        if(!list1&&!list2)return nullptr;
        if(!list1)return list2;
        if(!list2)return list1;
        pq.push(list1);
        pq.push(list2);
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        while(!pq.empty()){
            ListNode*curr=pq.top();
            pq.pop();
            temp->next=curr;
            temp=temp->next;
            if(curr->next){
                pq.push(curr->next);
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};