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
    ListNode*reverseList(ListNode*&node,int k){
        ListNode*temp=node;
        ListNode*prev=nullptr;
        while(k--){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        node=temp;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*newHead=nullptr;
        ListNode*prevTail=nullptr;
        while(temp){
            ListNode*curr=temp;
            int count=0;
            while(count<k&&curr){
                count++;
                curr=curr->next;
            }
            if(count<k)break;
            ListNode*groupStart=temp;
            ListNode*reverseHead=reverseList(temp,k);
            if(!newHead){
                newHead=reverseHead;
            }
            else{
                prevTail->next=reverseHead;
            }
            prevTail=groupStart;
        }
        if(prevTail){
            prevTail->next=temp;
        }
        return newHead?newHead:head;
    }
};