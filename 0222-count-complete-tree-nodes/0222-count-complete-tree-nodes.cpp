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
    int height(TreeNode* root) {
        return root == NULL ? -1: 1 + height(root->left);
    }
    
    public:
    int countNodes(TreeNode* root) {
        int nodes = 0, h = height(root);
        while (root) {
            if (height(root->right) == h - 1) {
                nodes += (1 << h);
                root = root->right;
            } else {
                nodes += (1 << (h-1));
                root = root->left;
            }
            h--;
        }
        return nodes;
    }
};