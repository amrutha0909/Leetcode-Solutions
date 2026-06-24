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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;
        unordered_map<int,int>mpp;
        ListNode*temp=head;
        while(temp){
            mpp[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(mpp[temp->val]==1){
                curr->next=temp;
                curr=curr->next;
            }
            temp=temp->next;
        }
        curr->next = nullptr;  
        return dummy->next;
    }
};