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
    TreeNode* subtreesAllDeepest(TreeNode* root, int &d) {
        int ld = 0; int rd = 0;
        auto left  = root->left ? subtreesAllDeepest(root->left, ld) : NULL;
        auto right  = root->right ? subtreesAllDeepest(root->right, rd) : NULL;
        d = max(ld, rd) + 1;
        if (ld == rd) return root;
        else return ld > rd ? left: right;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int d = 0;
        return root ? subtreesAllDeepest(root, d) : NULL;
    }
};