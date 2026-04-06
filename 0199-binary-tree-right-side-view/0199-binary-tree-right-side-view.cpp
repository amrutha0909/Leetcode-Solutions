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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        while(!q.empty()){
            int len=q.size();
            vector<int>level(len);
            for(int i=0;i<len;i++){
                auto node=q.front();
                q.pop();
                level[i]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            res.push_back(level[len-1]);
        }
        return res;
    }
};