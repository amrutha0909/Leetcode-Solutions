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
    TreeNode*build(int inorderStart,int inorderEnd,int preorderStart,int preorderEnd,vector<int>&inorder,vector<int>&preorder,unordered_map<int,int>&mpp){
        if(inorderStart>inorderEnd||preorderStart>preorderEnd)return nullptr;
        int rootVal=preorder[preorderStart];
        TreeNode*root=new TreeNode(rootVal);
        int inorderRootIndex=mpp[rootVal];
        int leftSubtreeSize=inorderRootIndex-inorderStart;
        root->left=build(inorderStart,inorderRootIndex-1,preorderStart+1,preorderStart+leftSubtreeSize,inorder,preorder,mpp);
        root->right=build(inorderRootIndex+1,inorderEnd,preorderStart+leftSubtreeSize+1,preorderEnd,inorder,preorder,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(0,inorder.size()-1,0,preorder.size()-1,inorder,preorder,mpp);
    }
};