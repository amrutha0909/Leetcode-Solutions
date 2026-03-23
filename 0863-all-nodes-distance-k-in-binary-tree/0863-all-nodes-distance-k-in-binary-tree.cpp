/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;
        unordered_map<int,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto top=q.front();
                q.pop();
                if(top->left){
                    parent[top->left->val]=top;
                    q.push(top->left);
                }
                if(top->right){
                    parent[top->right->val]=top;
                    q.push(top->right);
                }
            }
        }
        unordered_map<int,int>visited;
        q.push(target);
        while(k--&&!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto node=q.front();
                q.pop();
                visited[node->val]=1;
                if(node->left&&!visited[node->left->val]){
                    q.push(node->left);
                }
                if(node->right&&!visited[node->right->val]){
                    q.push(node->right);
                }
                if(parent[node->val]&&!visited[parent[node->val]->val]){
                    q.push(parent[node->val]);
                }
            }
        }
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};