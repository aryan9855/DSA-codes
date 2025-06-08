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
void inorder(TreeNode *root,vector<int>&inorderVals){
      if(root == NULL){
          return ;
      }
      inorder(root -> left , inorderVals);
      inorderVals.push_back(root -> val);
      inorder(root -> right ,inorderVals);
  }
  TreeNode* inorderToBST(int s , int e , vector<int>inorderVals){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode (inorderVals[mid]);
    root -> left = inorderToBST(s,mid-1,inorderVals);
    root -> right = inorderToBST(mid+1,e,inorderVals);
    return root;
  }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVals;
        inorder(root ,inorderVals);

        return inorderToBST(0,inorderVals.size()-1,inorderVals);        
    }
};