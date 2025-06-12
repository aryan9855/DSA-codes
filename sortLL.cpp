class Solution {
public:
    void sorted(vector<int>& ans) {
        sort(ans.begin(), ans.end());
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL) return head;

        vector<int> ans;
        ListNode* curr = head;

        while (curr != NULL) {
            ans.push_back(curr->val);
            curr = curr->next;
        }

        sorted(ans);

        curr = head;
        int i = 0;
        while (curr != NULL) {
            curr->val = ans[i++];
            curr = curr->next;
        }

        return head;
    }
};
