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
    bool isValid = true;
    int traverse(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        auto leftHeight = traverse(root->left) + 1;
        auto rightHeight = traverse(root->right) + 1;
        if (abs(leftHeight - rightHeight) > 1) isValid = false;
        return max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        traverse(root);
        return isValid;
    }
};

class Solution {
    bool isValid = true;
    int traverse(TreeNode* root) {
        if (!root->left && !root->right) return 1;
        auto leftHeight = root->left ? traverse(root->left) : 0;
        auto rightHeight = root->right ? traverse(root->right) : 0;
        if (abs(rightHeight-leftHeight) > 1) isValid = false;
        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root) traverse(root);
        return isValid;
    }
};