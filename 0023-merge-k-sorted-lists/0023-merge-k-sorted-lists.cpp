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
        if(!l1)return l2;
        if(!l2)return l1;
        if(l1->val<=l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
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