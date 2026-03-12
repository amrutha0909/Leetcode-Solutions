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
        if(!root)return {true,0,INT_MAX,INT_MIN};
        auto [leftIsBST, leftSum, leftMin, leftMax]=dfs(root->left);
        auto [rightIsBST, rightSum, rightMin, rightMax]=dfs(root->right);
        if(leftIsBST && rightIsBST && leftMax<root->val && rightMin>root->val){
            int sum=leftSum+rightSum+root->val;
            maxSum=max(maxSum,sum);
            int minVal=min(root->val,leftMin);
            int maxVal=max(root->val,rightMax);
            return {true,sum,minVal,maxVal};
        }
        return {false,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};