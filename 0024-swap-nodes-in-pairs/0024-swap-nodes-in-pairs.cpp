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
    ListNode* swapPairs(ListNode* head) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        while(prev->next && prev->next->next){
            ListNode*first=prev->next;//temp
            ListNode*second=first->next;//temp->next
            first->next=second->next;
            second->next=first;

            prev->next=second;//connect prev to swapped head (second is swapped head)
            prev=first; //make prev as swapped tail (first is swapped tail)
        }
        return dummy->next;
    }
};