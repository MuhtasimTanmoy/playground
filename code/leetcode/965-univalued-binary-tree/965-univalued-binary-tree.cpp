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
    bool isUnival = true;
    void traverse(TreeNode* root, int& val) {
        if (root->val != val) {
            isUnival = false;
            return;
        }
        if (root->left) traverse(root->left, val);
        if (root->right) traverse(root->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        int val;
        if (root) {
            val = root->val;
            traverse(root, val);
        }
        return isUnival;
    }
};