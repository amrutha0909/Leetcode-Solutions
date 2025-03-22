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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            vector<int>arr;
            if(list1==NULL&&list2==NULL){
                return list1;
            }
            if(list1==NULL){
                return list2;
            }
            else if(list2==NULL){
                return list1;
            }
            while(list1){
                arr.push_back(list1->val);
                list1=list1->next;
            }
            while(list2){
                arr.push_back(list2->val);
                list2=list2->next;
            }
            sort(arr.begin(),arr.end());
            ListNode*head=NULL;
            for(int i=0;i<arr.size();i++){
                ListNode*node=new ListNode(arr[i]);
                if(head==NULL){
                    head=node;
                }
                else{
                    ListNode*temp=head;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=node;
                }
            }
            return head;
        }
    };