/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode*slow1=head;
                while(slow1!=slow){
                    slow=slow->next;
                    slow1=slow1->next;
                }
                return slow1;
            }
        }
        return nullptr;
    }
};