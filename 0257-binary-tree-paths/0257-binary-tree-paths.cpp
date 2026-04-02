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
    void paths(TreeNode*root,string ans,vector<string>&res){
        if(!root)return;
        if(!ans.empty())ans+="->";
        ans+=to_string(root->val);
        if(!root->left&&!root->right){
            res.push_back(ans);
            return;
        }
        paths(root->left,ans,res);
        paths(root->right,ans,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return {""};
        vector<string>res;
        string ans="";
        paths(root,ans,res);
        return res;
    }
};