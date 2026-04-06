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
class BSTIterator {
public:
    TreeNode*curr;
    BSTIterator(TreeNode* root) {
        curr=root;
    }
    
    int next() {
        int val;
        while(curr){
            if(!curr->left){
                val=curr->val;
                curr=curr->right;
                return val;
            }
            else{
                TreeNode*pred=curr->left;
                while(pred->right&&pred->right!=curr){
                    pred=pred->right;
                }
                if(!pred->right){
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    pred->right=nullptr;
                    val=curr->val;
                    curr=curr->right;
                    return val;
                }
            }
        }
        return -1;
    }
    
    bool hasNext() {
        return curr!=nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */