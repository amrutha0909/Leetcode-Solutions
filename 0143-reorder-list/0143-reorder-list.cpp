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
    ListNode* reverseList(ListNode*node){
        ListNode*prev=nullptr;
        ListNode*temp=node;
        while(temp){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        node=temp;
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*list1=head;
        ListNode*list2=reverseList(slow->next);
        slow->next=nullptr;
        while(list2){
            ListNode*n1=list1->next;
            ListNode*n2=list2->next;
            list1->next=list2;
            list2->next=n1; //list2->next=list2->next;
            list1=n1; //moving list1 pointer to next
            list2=n2; //moving list2 pointer to next
        }
    }
};