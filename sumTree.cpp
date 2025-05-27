class Solution {
public:
    // Helper function returns: {isSumTree, sum of subtree}
    pair<bool, int> isSumTreeHelper(Node* root) {
        if (root == NULL){
            return {true, 0};
        }

        // Leaf node
        if (root->left == NULL && root->right == NULL){
            return {true, root->data};
        }
        else{
        pair<bool, int> left = isSumTreeHelper(root->left);
        pair<bool, int> right = isSumTreeHelper(root->right);

        bool isCurrentSum = root->data == left.second + right.second;
        bool isTreeSum = left.first && right.first && isCurrentSum;

        return {isTreeSum, root->data + left.second + right.second};
    }
    }

    bool isSumTree(Node* root) {
        return isSumTreeHelper(root).first;
    }
};