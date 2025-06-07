class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool ans(Node* root , int min ,int max){
        if(root == NULL){
            return true;
        }
        if(root -> data >= min && root -> data <= max){
        bool left = ans(root -> left , min , root-> data);
        bool right = ans(root-> right , root-> data , max);
        return left && right;
        }
        else{
            return false;
        }
    }
        
    bool isBST(Node* root) {
        // Your code here
        return ans(root , INT_MIN ,INT_MAX);
        
    }
};