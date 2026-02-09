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
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode*dummy=new ListNode(0);
        ListNode*curr=dummy;
        while(l1 && l2){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
                curr=curr->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
                curr=curr->next;
            }
        }
        while(l1){
            curr->next=l1;
            l1=l1->next;
            curr=curr->next;
        }
        while(l2){
            curr->next=l2;
            l2=l2->next;
            curr=curr->next;
        }
        return dummy->next;
    }
    ListNode*mergeSort(ListNode* head){
        if (!head || !head->next) return head;
        ListNode*temp=nullptr;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=nullptr;
        ListNode*l1=mergeSort(head);
        ListNode*l2=mergeSort(slow);
        return merge(l1,l2);
        
    }

    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        return mergeSort(head);
    }
};