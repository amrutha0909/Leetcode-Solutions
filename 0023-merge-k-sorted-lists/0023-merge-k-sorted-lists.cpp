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
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        while(l1&&l2){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        while(l1){
            temp->next=l1;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2){
            temp->next=l2;
            temp=temp->next;
            l2=l2->next;
        }
        return dummy->next;
    }
    ListNode*divideAndConquer(int left,int right,vector<ListNode*>&lists){
        if(left==right)return lists[left];
        int mid=left+(right-left)/2;
        ListNode*l1=divideAndConquer(left,mid,lists);
        ListNode*l2=divideAndConquer(mid+1,right,lists);
        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        return divideAndConquer(0,lists.size()-1,lists);
    }
};