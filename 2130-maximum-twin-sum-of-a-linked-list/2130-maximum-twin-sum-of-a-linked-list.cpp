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
    ListNode*reverseList(ListNode*node){
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
    int pairSum(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*temp=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*mid=slow->next;
        slow->next=nullptr;
        mid=reverseList(mid);
        int maxSum=0;
        while(mid){
            maxSum=max(maxSum,temp->val+mid->val);
            temp=temp->next;
            mid=mid->next;
        }
        return maxSum;
    }
};