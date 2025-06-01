class Solution {
public:
    void solve(TreeNode *root , int targetSum, int &cnt,vector<int> &ans){
        if(root == NULL){
            return;
        }
        ans.push_back(root -> val);
        solve(root-> left , targetSum,cnt ,ans);
        solve(root-> right , targetSum,cnt ,ans);
        long long int sum =0;
        for(int i = ans.size()-1; i>=0; i--){
            sum += ans[i];
            if(sum == targetSum){
                cnt++;
            }
        }
            ans.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        int cnt =0;
        solve(root , targetSum,cnt , ans);
        return cnt;
    }
}; 