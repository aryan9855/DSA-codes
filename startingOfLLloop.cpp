https://leetcode.com/problems/linked-list-cycle-ii/
// // 142. Linked List Cycle II
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode* fast = head;
        ListNode* slow = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast; // or return slow
            }
        }

        return NULL;
    }
};