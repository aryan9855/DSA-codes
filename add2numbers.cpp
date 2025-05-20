//https://leetcode.com/problems/add-two-numbers/
// Leetcode problem 2

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr= dummy ;
        int carry =0;
        while(l1 != NULL || l2 != NULL || carry !=0){
            int sum =0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1-> next;
            }
             if(l2 != NULL){
                sum += l2->val;
                l2 = l2-> next;
            }
            sum +=carry;
            carry = sum /10;
            int digit = sum %10;
            ListNode*  newNode = new ListNode(digit);
            curr -> next = newNode;
            curr = curr -> next;
        }
        
        return dummy -> next;
    }
};