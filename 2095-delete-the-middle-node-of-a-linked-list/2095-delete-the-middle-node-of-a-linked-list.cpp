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
    ListNode* deleteMiddle(ListNode* head) {
        int count=0;
        ListNode*temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count==1)return nullptr;
        int pos=count/2;
        temp=head;
        for(int i=0;i<pos-1&&temp;i++){
            temp=temp->next;
        }
        if(temp&&temp->next && temp->next->next){
            temp->next=temp->next->next;
        }
        else if(temp&&temp->next)temp->next=nullptr;
        return head;
    }
};