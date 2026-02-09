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
        if(!head||k==1)return head;     
        ListNode*temp=head;
        ListNode*newHead=nullptr;
        ListNode*prevTail=nullptr;
        while(temp){
            int cnt=0;
            ListNode*check=temp;
            while(cnt<k&&check){
                cnt++;
                check=check->next;
            }
            if(cnt<k)break;
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