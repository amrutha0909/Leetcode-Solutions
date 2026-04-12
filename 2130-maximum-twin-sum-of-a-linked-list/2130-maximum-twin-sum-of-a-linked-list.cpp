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
    ListNode*reverseL(ListNode*&node){
        ListNode*prev=nullptr;
        while(node){
            ListNode*front=node->next;
            node->next=prev;
            prev=node;
            node=front;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        if(!head)return 0;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*second=slow->next;
        ListNode*first=head;
        ListNode*rev=reverseL(second);
        int maxSum=0;
        while(rev){
            maxSum=max(maxSum,first->val+rev->val);
            first=first->next;
            rev=rev->next;
        }
        return maxSum;
    }
};