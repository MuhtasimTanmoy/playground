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
public:
    int sumNumbers(TreeNode* root, int prev = 0) {
        if (!root->left && !root->right) res += prev + root->val;
        if (root->left) sumNumbers(root->left, (prev + root->val) * 10);
        if (root->right) sumNumbers(root->right, (prev + root->val) * 10);
        return res;
    }
};