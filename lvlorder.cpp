/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL ) return ans;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int lvlSize = q.size();

            vector<int> currLvl;

            for(int i =0 ;i< lvlSize;i++){
                TreeNode* temp = q.front();
                q.pop();
                currLvl.push_back(temp -> val);

                if(temp -> left != NULL) q.push(temp -> left);
                if(temp -> right != NULL) q.push(temp -> right);
            
            }
            ans.push_back(currLvl);
        }
        return ans;
    }
};