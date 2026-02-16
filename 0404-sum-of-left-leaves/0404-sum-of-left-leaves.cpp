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
    bool left=false;
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left && !root->right && left){
            sum+=root->val;
        }
        if(root->left){
            left=true;
            sumOfLeftLeaves(root->left);
        }
        if(root->right){
            left=false;
            sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};