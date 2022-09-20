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
    int res = INT_MAX, cache = -1;
    void traverse (TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        if (cache != -1) res = min(res, abs(root->val - cache));
        cache = root->val;
        traverse(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        return res;
    }
};