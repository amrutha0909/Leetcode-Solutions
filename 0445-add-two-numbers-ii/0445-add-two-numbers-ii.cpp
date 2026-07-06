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
    ListNode*reverseL(ListNode*node){
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ll1=reverseL(l1);
        ListNode*ll2=reverseL(l2);
        int carry=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        while(ll1||ll2||carry){
            int sum=carry;
            if(ll1){
                sum+=ll1->val;
                ll1=ll1->next;
            }
            if(ll2){
                sum+=ll2->val;
                ll2=ll2->next;
            }
            ListNode*node=new ListNode(sum%10);
            carry=sum/10;
            temp->next=node;
            temp=temp->next;
        }
        ListNode*ans=reverseL(dummy->next);
        return ans;
    }
};