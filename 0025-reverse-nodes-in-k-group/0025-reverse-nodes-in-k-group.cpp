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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count<k)return head;
        count=0;
        temp=head;
        ListNode*prev=nullptr;
        ListNode*front=nullptr;
        while(temp && count<k){
            count++;
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        if(temp!=nullptr)head->next=reverseKGroup(temp,k);
        return prev;

    }
};