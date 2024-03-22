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
    int go(TreeNode* rt) {
        if (!rt) return 0;
        auto l = go(rt->left), r = go(rt->right);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        go(root);
        return res;
    }
};