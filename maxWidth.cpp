/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = 0;

        queue<pair<TreeNode*, int>> q; 

        q.push({root, 1});

        while (!q.empty()){
            int size = q.size();
            int minAtLevel = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                int currIndex = q.front().second - minAtLevel + 1; 
                TreeNode* node = q.front().first;
                q.pop(); 
                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex; 
                if (node->left != NULL) q.push({node->left, 2LL * currIndex});
                if (node->right != NULL) q.push({node->right, 2LL * currIndex + 1});
            }
            ans = max(ans, last - first + 1); 
        }
        return ans;
    }
};