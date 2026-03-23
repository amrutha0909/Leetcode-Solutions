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
    TreeNode*buildHelper(vector<int>&preorder,vector<int>&inorder,int preorderStart,int preorderEnd,int inorderStart,int inorderEnd,unordered_map<int,int>&index){
        if(inorderStart>inorderEnd||preorderStart>preorderEnd)return nullptr;
        int rootVal=preorder[preorderStart];
        TreeNode*root=new TreeNode(rootVal);
        int inorderRootIndex=index[rootVal];
        int leftSubtreeSize=inorderRootIndex-inorderStart;
        root->left=buildHelper(preorder,inorder,preorderStart+1,preorderStart+leftSubtreeSize,inorderStart,inorderRootIndex-1,index);
        root->right=buildHelper(preorder,inorder,preorderStart+leftSubtreeSize+1,preorderEnd,inorderRootIndex+1,inorderEnd,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>index;
        for(int i=0;i<inorder.size();i++){
            index[inorder[i]]=i;
        }
        return buildHelper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,index);
    }
};