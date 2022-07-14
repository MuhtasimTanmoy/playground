/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        auto foundFromLeft = traverse(root->left, p, q);
        auto foundFromRight = traverse(root->right, p, q);
        if (foundFromLeft && foundFromRight) return root;
        if (foundFromLeft || foundFromRight) if (root == p || root == q) return root;
        if (foundFromLeft) return foundFromLeft;
        if (foundFromRight) return foundFromRight;
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverse(root, p, q);
    }
};