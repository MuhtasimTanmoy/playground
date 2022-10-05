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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (!root->left) return maxDepth(root->right) + 1;
        if (!root->right) return maxDepth(root->left) + 1;
        return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
};