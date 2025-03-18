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
        bool isPalindrome(ListNode* head) {
            stack<int>s;
            ListNode*temp=head;
            long long int count=0;
            long long int cnt=0;
            if(head==NULL){
                return false;
            }
            while(temp!=NULL){
                count++;
            s.push(temp->val);
            temp=temp->next;
            }
            ListNode*current=head;
            while(current->next!=NULL){
            if(s.top()!=current->val){
                return false;
            }
            s.pop();
            current=current->next;
            }
            return true;
        }
    };