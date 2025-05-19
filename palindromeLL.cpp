//https://leetcode.com/problems/palindrome-linked-list/
// 234. Palindrome Linked List

class Solution {
public:
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=NULL && fast->next !=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return true;
        } 
        ListNode* slow = getMid(head);

        // Step 2: Reverse the second half of the list
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        ListNode *next = nullptr;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Compare the first and second halves
        ListNode *first = head;
        ListNode *second = prev;
        while (second != NULL) {
            if (first->val != second->val){
                return false;
            } 
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
