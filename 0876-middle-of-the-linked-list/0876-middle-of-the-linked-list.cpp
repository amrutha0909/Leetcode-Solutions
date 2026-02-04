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
    ListNode* middleNode(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;     
        } 
        while(fast&&fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(length%2==0)return slow->next;
        return slow;
    }
};