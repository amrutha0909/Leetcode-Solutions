/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null)return null;
        int count=0;
        ListNode temp=head;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        if(count==0 || count==k)return head;
        k%=count;
        temp=head;
        for(int i=0;i<count-k-1;i++){
            temp=temp.next;
        }
        ListNode dummy=new ListNode(-1);
        dummy.next=temp.next;
        temp.next=null;
        ListNode curr=dummy;
        while(curr.next!=null){
            curr=curr.next;
        }
        curr.next=head;
        return dummy.next;
    }
}