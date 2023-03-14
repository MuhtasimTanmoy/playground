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
    int sumNumbers(TreeNode* r, int prev = 0) {
        if (!r) return 0;
        auto val = prev + r->val;
        if (!r->left && !r->right) return val;
        return sumNumbers(r->left, val * 10) 
             + sumNumbers(r->right, val * 10);
    }
};