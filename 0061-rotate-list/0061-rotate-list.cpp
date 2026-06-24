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
        int count=0;
        ListNode*temp=head;
        if(!head)return nullptr;
        while(temp){
            count++;
            temp=temp->next;
        }

        k%=count;
        int d=count-k;
        count=0;
        temp=head;
        while(count<d-1){
            count++;
            temp=temp->next;
        }
        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;
        curr->next=temp->next;
        temp->next=nullptr;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=head;
        return dummy->next;
    }
};