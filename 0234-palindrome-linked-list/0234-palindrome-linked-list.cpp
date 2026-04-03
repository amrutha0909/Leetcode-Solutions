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
    ListNode*reverseList(ListNode*&node){
        ListNode*temp=node;
        ListNode*prev=nullptr;
        while(temp){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
         if (!head || !head->next) return true;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*secondHalf=reverseList(slow->next);
        ListNode*temp=head;
        while(secondHalf){
            if(temp->val!=secondHalf->val)return false;
            temp=temp->next;
            secondHalf=secondHalf->next;
        }
        slow->next = reverseList(secondHalf);
        return true;
    }
};