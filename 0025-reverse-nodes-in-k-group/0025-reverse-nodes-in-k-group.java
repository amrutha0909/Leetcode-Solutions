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
    public ListNode reverseKGroup(ListNode head, int k) {
        int count=0;
        ListNode temp=head;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        if(count<k)return head;
        count=0;
        ListNode prev=null;
        temp=head;
        ListNode front=null;
        while(temp!=null && count<k){
            count++;
            front=temp.next;
            temp.next=prev;
            prev=temp;
            temp=front;
        }
        if(front!=null)head.next=reverseKGroup(front,k);
        return prev;
    }
}