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
    int pairSum(ListNode* head) {
        vector<int>nums;
        ListNode*temp=head;
        if(!head)return 0;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int maxSum=0;
        int left=0,right=nums.size()-1;
        while(left<right){
            maxSum=max(maxSum,nums[left]+nums[right]);
            left++;
            right--;
        }
        return maxSum;
    }
};