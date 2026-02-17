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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,vector<int>>>mp;
        q.push({root,{0,0}});
        vector<vector<int>>ans;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode*node=it.first;
            int col=it.second.first;
            int row=it.second.second;
            mp[col][row].push_back(node->val);
            if(node->left){
                q.push({node->left,{col-1,row+1}});
            }
            if(node->right){
                q.push({node->right,{col+1,row+1}});
            }
        }
        for(auto&colPair:mp){
            vector<int>temp;
            for(auto&rowPair:colPair.second){
                sort(rowPair.second.begin(),rowPair.second.end());
                for(int val:rowPair.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};