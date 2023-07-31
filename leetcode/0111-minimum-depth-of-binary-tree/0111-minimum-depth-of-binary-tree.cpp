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
    int minDepth(TreeNode* r, int curr = 1) {
        if (!r) return curr == 1 ? 0: INT_MAX;
        if (!r->left && !r->right) return curr;
        auto left = minDepth(r->left, curr + 1),
             right = minDepth(r->right, curr + 1);
        return min(left, right);
    }
};