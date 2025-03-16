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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(!head||left==right){
                return head;
            }
            ListNode*temp=head;
            ListNode*prev=NULL;
            for(int i=1;i<left;i++){
                prev=temp;
                temp=temp->next;
            }
            ListNode*ExtraTail=temp;
            ListNode*ExtraPrev=prev;
            ListNode*front=NULL;
            for(int i=left;i<=right;i++){
                front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
            }
            if(ExtraPrev){
                ExtraPrev->next=prev;
            }
            else{
                head=prev;
            }
            ExtraTail->next=temp;
            return head;
        }
    };