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
    int maxAncestorDiff(TreeNode* root, int currMax = INT_MIN, int currMin = INT_MAX) {
        if (!root) return currMax - currMin;
        currMax = max(root->val, currMax);
        currMin = min(root->val, currMin);
        auto left = maxAncestorDiff(root->left, currMax, currMin);
        auto right = maxAncestorDiff(root->right, currMax, currMin);
        return max(left, right);
    }
};