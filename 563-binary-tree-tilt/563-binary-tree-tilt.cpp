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
    int result = 0;
    int traverse(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        auto leftVal = root->left ? traverse(root->left) : 0;
        auto rightVal = root->right ? traverse(root->right) : 0;
        result += abs(leftVal - rightVal);
        return root->val + leftVal + rightVal;
    }
public:
    int findTilt(TreeNode* root) {
        if (root) traverse(root);
        return result;
    }
};