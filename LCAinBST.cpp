class Solution {
  public:
   Node* solve(Node* root , Node*n1,Node*n2){
       if(root == NULL){
           return NULL;
       }
       if(root -> data> n1-> data && root -> data > n2-> data){
           return solve(root -> left , n1 , n2);
       }
       
       if(root-> data  < n1-> data&& root -> data < n2->data){
           return solve(root -> right , n1 , n2);
       }
       return root ;
   }
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
                return solve(root , n1,n2);
        
    }
};