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
    int res = 0;
    void go(TreeNode* root, bool is_left, int depth) {
        if (!root) return;
        go(root->left, true, is_left ? 1: depth + 1);
        go(root->right, false, is_left ? depth + 1: 1);
        res = max(res, depth);
    }
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        go(root, true, 0);
        go(root, false, 0);
        return res;
    }
};