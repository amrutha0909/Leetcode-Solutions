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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        ListNode*dummy=new ListNode(0);
        int count=0;
        ListNode*temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        k=k%count;
        int c=(count-k);
        temp=head;
        int d=0;
        while(d<c-1){
            d++;
            temp=temp->next;
        }
        dummy->next=temp->next;
        temp->next=nullptr;
        ListNode*curr=dummy;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=head;
        return dummy->next;
    }
};