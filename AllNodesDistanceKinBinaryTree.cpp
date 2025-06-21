/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode*root ,unordered_map<TreeNode* , TreeNode*> &parent,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr -> left != NULL){
                parent[curr-> left] = curr;
                q.push(curr -> left);
            }

            if(curr -> right != NULL){
                parent[curr-> right] = curr;
                q.push(curr -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        markParent(root , parent,target);

        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_lvl = 0;
        
        while(!q.empty()){
            int size = q.size();
           if(curr_lvl == k) break;
            curr_lvl++;
            for(int i =0 ;i< size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr -> left && !visited[curr-> left]){
                    q.push(curr -> left);
                    visited[curr -> left] = true;
                }

                if(curr -> right && !visited[curr-> right]){
                    q.push(curr -> right);
                    visited[curr -> right] = true;
                }

                if(parent[curr]  && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr-> val);
        }
           return ans;
    }
};