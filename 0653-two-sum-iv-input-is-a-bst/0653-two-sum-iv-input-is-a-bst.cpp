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
    vector<int>inorder;
    void inorderList(TreeNode*root){
        if(root->left)inorderList(root->left);
        inorder.push_back(root->val);
        if(root->right)inorderList(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        inorderList(root);
        int l=0;
        int r=inorder.size()-1;
        while(l<r){
            if(inorder[l]+inorder[r]==k)return true;
            else if(inorder[l]+inorder[r]>k)r--;
            else l++;
        }
        return false;
    }
};