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
    int count = 0;
    
    TreeNode* ancestorIfFound(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        auto left = ancestorIfFound(root->left, p, q);
        auto right = ancestorIfFound(root->right, p, q);
        if (root == p || root == q) {
            count++;
            return root;
        }
        if (left && right) return root;
        else return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto res = ancestorIfFound(root, p, q);
        return count == 2 ? res : NULL;
    }
};