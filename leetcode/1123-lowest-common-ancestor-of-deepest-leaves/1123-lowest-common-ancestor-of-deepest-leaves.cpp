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
    TreeNode *postorder(TreeNode *root, int &d) {
        int ld = 0, rd = 0;
        if (!root) return root;
        
        auto left = postorder(root->left, ld);
        auto right = postorder(root->right, rd);
        
        d = max(ld, rd) + 1;
        if (ld == rd) return root;
        else if (ld > rd) return left;
        else return right;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int d = 0;
        return postorder(root, d);
    }
};