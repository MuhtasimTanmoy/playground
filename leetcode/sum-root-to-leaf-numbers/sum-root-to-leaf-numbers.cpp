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
    int traverse(TreeNode* root, int val) {
        if (!root) return 0;
        if (!root->left && !root->right) return 10 * val + root->val;
        
        int sum = 0;
        if (root->left) sum += traverse(root->left, 10 * val + root->val);
        if (root->right) sum += traverse(root->right, 10 * val + root->val);
        return sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return traverse(root, 0);
    }
};