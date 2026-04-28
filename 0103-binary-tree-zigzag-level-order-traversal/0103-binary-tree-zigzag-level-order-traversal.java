/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root==null)return List.of();
        List<List<Integer>>res=new ArrayList<>();
        Queue<TreeNode>q=new LinkedList<>();
        q.offer(root);
        boolean leftToRight=true;
        while(!q.isEmpty()){
            int len=q.size();
            List<Integer>ans=new ArrayList<>();
            for(int i=0;i<len;i++){
                TreeNode node=q.peek();q.poll();
                ans.add(node.val);
                if(node.left!=null)q.offer(node.left);
                if(node.right!=null)q.offer(node.right);
            }
            if(leftToRight)res.add(ans);
            else {
                Collections.reverse(ans);
                res.add(ans);
            }
            leftToRight=!leftToRight;
        }
        return res;
    }
}