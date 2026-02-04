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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head)return nullptr;
        ListNode*prev=nullptr;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;
        }
        if(length==1)return nullptr;
        while(fast&&fast->next&&fast->next->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(length%2==0){
            prev=slow;
            slow=slow->next;
            
        }
        ListNode*del=prev->next;
        prev->next=del->next;
        delete del;
        return head;
    }
};