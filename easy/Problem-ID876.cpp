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
        ListNode* middleNode(ListNode* head) {
            ListNode*current=head;
            int length=0;
            while(current!=nullptr){
                length++;
                current=current->next;
            }
            ListNode*temp=head;
            for(int i=0;i<(length)/2;i++){
                temp=temp->next;
            }
            ListNode*sol=temp;
            return sol;
    
        }
    };