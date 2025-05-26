class Solution {
    private:
    int height(TreeNode* root , int &ans){
        if(root == NULL){
            return 0;
        }
        int left = height(root-> left,ans);
        int right = height(root -> right , ans);
        ans = max(ans,left + right +1);
        return max(left , right)+1;
    }
public:
int ans =0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root,ans);
        return ans-1 ;
    }
};