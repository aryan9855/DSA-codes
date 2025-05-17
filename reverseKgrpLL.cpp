//https://leetcode.com/problems/reverse-nodes-in-k-group/
// 25. Reverse Nodes in k-Group
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* node = head;
        int count = 0;
        while (node != nullptr && count < k) {
            node = node->next;
            count++;
        }
        if (count < k) {
            return head; // Fewer than k nodes; no reversal
        }

        // Step 1: Reverse first k nodes 
        ListNode* forward = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        count = 0;
        while (curr != nullptr && count < k) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        // Step 2: Recurse on remaining list
        if (forward != nullptr) {
            head->next = reverseKGroup(forward, k);
        }

        return prev;
    }
};