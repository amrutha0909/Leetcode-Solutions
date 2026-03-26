class Solution {
public:
    void insertAtEnd(ListNode*& head, int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            insertAtEnd(head, sum % 10);
        }

        return head;
    }
};
