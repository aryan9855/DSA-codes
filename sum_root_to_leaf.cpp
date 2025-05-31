class Solution {
public:
        void solve(TreeNode* root , string path , int& totalSum){
            if(root == NULL){
                return;
            }
            path += to_string(root -> val);
            if(root -> left == NULL && root -> right == NULL){
                totalSum +=stoi(path);
                return;
            }
            solve(root -> left , path, totalSum);
            solve(root -> right , path , totalSum);
            
        }
    int sumNumbers(TreeNode* root) {
        int totalSum =0;
        solve(root , "",totalSum);
        return totalSum;
    }
};