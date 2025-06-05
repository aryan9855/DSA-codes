class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root ;
        while(curr != NULL){
            if(curr -> left != NULL){
                TreeNode* pred = curr -> left;
                while(pred -> right != NULL){
                    pred = pred -> right;
                }
                pred -> right = curr -> right ;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};