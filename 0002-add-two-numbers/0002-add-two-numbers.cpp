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
    void insertEnd(ListNode*&head,int value){
        ListNode*node=new ListNode(value);
        if(!head){
            head=node;
            return;
        }
        ListNode*temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode*head=nullptr;
        while(l1||l2||carry){
            int sum=carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            int value=(sum)%10;
            carry=sum/10;
            insertEnd(head,value);
        }
        return head;
    }
};