class Solution {
  public:
    // Helper function returns size of largest BST in subtree
    // It updates minVal, maxVal, size, and returns whether subtree is BST
    bool solve(Node* root, int &maxSize, int &minVal, int &maxVal, int &size) {
        if (root == NULL) {
            minVal = INT_MAX;
            maxVal = INT_MIN;
            size = 0;
            return true;
        }

        int leftMin, leftMax, leftSize;
        int rightMin, rightMax, rightSize;

        bool leftIsBST = solve(root->left, maxSize, leftMin, leftMax, leftSize);
        bool rightIsBST = solve(root->right, maxSize, rightMin, rightMax, rightSize);

        if (leftIsBST && rightIsBST && root->data > leftMax && root->data < rightMin) {
            if (root->left != NULL) {
                minVal = leftMin;
            } else {
                minVal = root->data;
            }

            if (root->right != NULL) {
                maxVal = rightMax;
            } else {
                maxVal = root->data;
            }

            size = leftSize + rightSize + 1;
            if (size > maxSize) {
                maxSize = size;
            }

            return true;
        }

        // Not BST
        size = 0;
        return false;
    }

    int largestBst(Node *root) {
        int maxSize = 0;
        int minVal, maxVal, size;
        solve(root, maxSize, minVal, maxVal, size);
        return maxSize;
    }
};
