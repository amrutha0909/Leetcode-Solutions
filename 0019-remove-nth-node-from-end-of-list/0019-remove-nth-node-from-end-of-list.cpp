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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        if(!head)return nullptr;
        ListNode*temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==1)return nullptr;
        if(count==n){
            ListNode*t=head;
            head=head->next;
            delete t;
            return head;
        }
        if(count<n)return head;
        int pos=count-n+1;
        temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        if(temp->next && temp->next->next)temp->next=temp->next->next;
        else temp->next=nullptr;
        return head;
    }
};