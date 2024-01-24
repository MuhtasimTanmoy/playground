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
    int go(TreeNode* rt, int val) {
        if (!rt) return 0;
        auto l = go(rt->left, rt->val), r = go(rt->right, rt->val);
        res = max(res, l + r);
        return rt->val == val ? 1 +  max(l, r): 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        go(root, -1);
        return res;
    }
};