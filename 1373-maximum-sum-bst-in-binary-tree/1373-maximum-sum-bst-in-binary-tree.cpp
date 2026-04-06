/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum=0;
    tuple<bool,int,int,int>dfs(TreeNode*root){
        if(!root)return {true,INT_MAX,INT_MIN,0};
        auto [leftIsBST,leftMin,leftMax,leftSum]=dfs(root->left);
        auto [rightIsBST,rightMin,rightMax,rightSum]=dfs(root->right);
        if(leftIsBST&&rightIsBST&&leftMax<root->val&&rightMin>root->val){
            int sum=leftSum+rightSum+root->val;
            maxSum=max(maxSum,sum);
            int minVal=min(leftMin,root->val);
            int maxVal=max(rightMax,root->val);
            return {true,minVal,maxVal,sum};
        }
        return {false,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};