class Solution {
  public:
  void inorder(Node *root,vector<int>&inorderVals){
      if(root == NULL){
          return ;
      }
      inorder(root -> left , inorderVals);
      inorderVals.push_back(root -> data);
      inorder(root -> right ,inorderVals);
  }
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int>inorderVals;
        inorder(root,inorderVals);
        
        int i = 0;
        int j =inorderVals.size()-1;
        while(i<j){
            int sum = inorderVals[i]+inorderVals[j];
            if(sum == target){
                return true;
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
            
        }
        return false;
    }
};