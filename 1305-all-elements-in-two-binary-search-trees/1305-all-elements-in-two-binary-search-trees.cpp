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
 
    void inorder(TreeNode*root, vector<int>&ans){
        if(!root)return;
        if(root->left)inorder(root->left,ans);
        ans.push_back(root->val);
        if(root->right)inorder(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        vector<int>ans2;
        inorder(root1,ans1);
        inorder(root2,ans2);
        int i=0,j=0,k=0;
        int n=ans1.size(),m=ans2.size();
        vector<int>ans(n+m);
        while(i<n&&j<m){
            if(ans1[i]<=ans2[j]){
                ans[k]=ans1[i];
                k++;
                i++;
            }
            else{
                ans[k]=ans2[j];
                k++;
                j++;
            }
        }
        while(i<n){
            ans[k]=ans1[i];
            k++;
            i++;
        }
        while(j<m){
            ans[k]=ans2[j];
            k++;
            j++;
        }
        return ans;
    }
};