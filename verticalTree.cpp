class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        if (root == NULL) {
            return {};
        }

        q.push({root, {0, 0}}); 

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val); 

            if (frontNode->left != NULL) {
                q.push({frontNode->left, {hd - 1, lvl + 1}});
            }
            if (frontNode->right != NULL) {
                q.push({frontNode->right, {hd + 1, lvl + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                sort(j.second.begin(), j.second.end());  
                for (int k : j.second) {
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }

        return ans;
    }
};