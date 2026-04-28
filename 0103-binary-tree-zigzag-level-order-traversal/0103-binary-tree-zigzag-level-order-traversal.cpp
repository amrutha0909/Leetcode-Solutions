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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>result;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int len=q.size();
            vector<int>ans;
            for(int i=0;i<len;i++){
                auto node=q.front();q.pop();
                ans.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(leftToRight)result.push_back(ans);
            else{
                reverse(ans.begin(),ans.end());
                result.push_back(ans);
            }
            leftToRight=!leftToRight;
        }
        return result;
    }
};