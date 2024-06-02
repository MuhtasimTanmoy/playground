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
    int sumOfLeftLeaves(TreeNode* root, bool fromleft = false) {
        if (!root) return 0;
        if (!root->left && !root->right)
            if (fromleft)
                return root->val;
        return sumOfLeftLeaves(root->left, true) 
             + sumOfLeftLeaves(root->right, false);
    }
};