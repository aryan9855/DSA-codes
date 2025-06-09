class Solution {
  public:
    void inorder(Node* root , vector<int> &in){
        if(root == NULL){
            return;
        }
        inorder(root -> left,in);
        in.push_back(root -> data);
        inorder(root -> right,in);
    }
    
    vector<int> mergedArrays(vector<int> &a , vector<int> &b){
        vector<int> ans(a.size() + b.size());
        int i = 0, j = 0, k = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                ans[k++] = a[i++];
            } else {
                ans[k++] = b[j++];
            }
        }
        while(i < a.size()) {
            ans[k++] = a[i++];
        }
        while(j < b.size()) {
            ans[k++] = b[j++];
        }
        return ans;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);
        
        return mergedArrays(bst1, bst2);
    }
};
