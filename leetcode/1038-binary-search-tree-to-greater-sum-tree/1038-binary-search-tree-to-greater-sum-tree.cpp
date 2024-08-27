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
    int accumulator = 0;
    TreeNode* bstToGst(TreeNode* r) {
        if ( !r ) return nullptr;
        bstToGst(r->right);
        r->val += accumulator;
        accumulator = r->val;
        bstToGst(r->left);
        return r;
    }
};