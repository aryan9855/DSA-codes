class Solution {
public:
         TreeNode* solve(vector<int>& preorder, int mini, int maxi, int& i) {
        if (i >= preorder.size()|| preorder[i] < mini || preorder[i] > maxi) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, mini, root->val, i);
        root->right = solve(preorder, root->val, maxi, i);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder, INT_MIN, INT_MAX, i);
    }
};