class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int inorderStart, int inorderEnd, int preorderStart, int preorderEnd, unordered_map<int, int>& index) {
            if (inorderStart > inorderEnd || preorderStart > preorderEnd) {
                return nullptr;
            }
            int rootVal = preorder[preorderStart];
            TreeNode* root = new TreeNode(rootVal);
            int inorderRootIndex = index[rootVal];
            int leftSubtreeSize = inorderRootIndex - inorderStart;
            root->left = buildTreeHelper(inorder, preorder, inorderStart, inorderRootIndex - 1, preorderStart+1, preorderStart + leftSubtreeSize, index);
            root->right = buildTreeHelper(inorder, preorder, inorderRootIndex + 1, inorderEnd, preorderStart + leftSubtreeSize+1, preorderEnd, index);
            return root;
        }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1, index);
    }
    
};
