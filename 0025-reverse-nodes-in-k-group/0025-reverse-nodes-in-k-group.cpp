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
        ListNode*prev=nullptr;
        ListNode*temp=node;
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
        if(!head)return nullptr;
        ListNode*newHead=nullptr;
        ListNode*prevTail=nullptr;
        ListNode*temp=head;
        while(temp){
            ListNode*curr=temp;
            int count=0;
            while(count<k&&curr){
                count++;
                curr=curr->next;
            }
            if(count<k)break;
            ListNode*groupStart=temp;
            ListNode*revHead=reverseList(temp,k);
            if(!newHead){
                newHead=revHead;
            }
            else{
                prevTail->next=revHead;
            }
            prevTail=groupStart;
        }
        if(prevTail){
            prevTail->next=temp;
        }
        return newHead?newHead:head;
    }
};