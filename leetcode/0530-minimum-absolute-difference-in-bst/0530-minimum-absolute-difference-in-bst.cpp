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
    int prev = -1, ans = INT_MAX;
    void go(TreeNode* root) {
        if (!root) return;
        go(root->left);
        if (prev != -1) ans = min(ans, abs(root->val - prev));
        prev = root->val;
        go(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        go(root);
        return ans;
    }
};