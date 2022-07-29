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
    int maxLen = 0;
    int calc(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        auto left = calc(root->left);
        auto right = calc(root->right);
        maxLen = max(maxLen, left + right);
        return max(left, right) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        calc(root);
        return maxLen;
    }
};