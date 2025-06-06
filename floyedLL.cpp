//https://leetcode.com/problems/linked-list-cycle/description/
// 141. Linked List Cycle

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};