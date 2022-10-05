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
    void traverse(TreeNode* root, int val) {
        if (!root) return;
        if (val < root->val)
            if (root->left) traverse(root->left, val);
            else root->left = new TreeNode(val);
        else if (val > root->val)
            if (root->right) traverse(root->right, val);
            else root->right = new TreeNode(val);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        traverse(root, val);
        return root;
    }
};