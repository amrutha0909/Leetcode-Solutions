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
        int count=0;
        ListNode*temp=head;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) return head;
        count=0;
        ListNode*prev=nullptr;
        temp=head;
        ListNode*front=nullptr;
        while(temp&&count<k){
            count++;
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        if(front)head->next=reverseKGroup(front,k);
        return prev;
    }
};