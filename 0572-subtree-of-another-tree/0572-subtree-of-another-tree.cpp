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
    bool sameTree(TreeNode*root, TreeNode*subRoot){
        if(!root&&!subRoot)return true;
        if(!root)return false;
        if(!subRoot)return false;
        if(root->val!=subRoot->val)return false;
        return sameTree(root->left,subRoot->left)&&sameTree(root->right,subRoot->right);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return sameTree(root,subRoot)||sameTree(root->left,subRoot)||sameTree(root->right,subRoot);
    }
};