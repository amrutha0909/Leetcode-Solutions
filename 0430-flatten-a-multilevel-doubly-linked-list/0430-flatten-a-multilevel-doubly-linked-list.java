/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node flatten(Node head) {
        Stack<Node>st=new Stack<>();
        if(head==null)return null;
        st.push(head);
        Node prev=null;
        while(!st.isEmpty()){
            Node curr=st.peek();
            st.pop();
            if(prev!=null){
                prev.next=curr;
                curr.prev=prev;
            }
            if(curr.next!=null){
                st.push(curr.next);
            }
            if(curr.child!=null){
                st.push(curr.child);
                curr.child=null;
            }
            prev=curr;
        }
        return head;
    }
}