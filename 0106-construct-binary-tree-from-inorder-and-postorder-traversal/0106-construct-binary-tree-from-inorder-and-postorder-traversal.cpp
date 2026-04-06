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
    TreeNode*build(int inorderStart,int inorderEnd,int postorderStart,int postorderEnd,vector<int>&inorder,vector<int>&postorder,unordered_map<int,int>&mpp){
        if(inorderStart>inorderEnd||postorderStart>postorderEnd)return nullptr;
        int rootVal=postorder[postorderEnd];
        TreeNode*root=new TreeNode(rootVal);
        int inorderRootIndex=mpp[rootVal];
        int leftSubtreeSize=inorderRootIndex-inorderStart;
        root->left=build(inorderStart,inorderRootIndex-1,postorderStart,postorderStart+leftSubtreeSize-1,inorder,postorder,mpp);
        root->right=build(inorderRootIndex+1,inorderEnd,postorderStart+leftSubtreeSize,postorderEnd-1,inorder,postorder,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder,mpp);
    }
};