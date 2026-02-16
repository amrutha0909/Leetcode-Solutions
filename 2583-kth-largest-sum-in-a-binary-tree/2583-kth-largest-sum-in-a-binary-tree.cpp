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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        vector<long long>sums;
        while(!q.empty()){
            int len=q.size();
            long long sum=0;
            for(int i=0;i<len;i++){
                TreeNode*node=q.front();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
            }
            sums.push_back(sum);
        }
        sort(sums.begin(),sums.end());
        if(sums.size() < k) return -1;
        return sums[sums.size()-k];
    }
};