class Solution {
  public:
  void solve(Node *root, int k, int node,vector<int> &path,int &ans){
      if(root == NULL){
          return;
      }
      path.push_back(root -> data);
      if(root ->data == node){
          int index = path.size()-k-1;
          if(index >=0){
              ans=path[index];
          }
          else{
              ans =-1;
          }
          return;
      }
          solve(root -> left , k,node,path,ans);
          solve(root -> right , k ,node ,path,ans);
          path.pop_back();
  }
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        int ans =-1;
        vector<int> path;
        solve(root ,k,node,path,ans);
        return ans;
    }
};
