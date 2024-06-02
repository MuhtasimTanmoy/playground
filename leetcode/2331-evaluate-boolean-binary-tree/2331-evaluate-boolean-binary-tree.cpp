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
    bool evaluateTree(TreeNode* r) {
        if (!r) return false;
        if (r->val == 0 || r->val == 1) return r->val;
        if (r->val == 2) return evaluateTree(r->left) || evaluateTree(r->right);
        if (r->val == 3) return evaluateTree(r->left) && evaluateTree(r->right);
        throw "error";
    }
};