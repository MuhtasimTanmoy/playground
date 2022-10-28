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
    int sum = 0;
    void traverse(TreeNode* root) {
        if (!root) return;
        
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};