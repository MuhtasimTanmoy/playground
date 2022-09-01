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
    int counter = 0;
    void traverse(TreeNode* root, int maxSoFar) {
        if (!root) return;
        if (root->val >= maxSoFar) {
            maxSoFar = root->val;
            counter++;
        }
        if (root->left) traverse(root->left, maxSoFar);
        if (root->right) traverse(root->right, maxSoFar);
    }
public:
    int goodNodes(TreeNode* root) {
        traverse(root, INT_MIN);
        return counter;
    }
};