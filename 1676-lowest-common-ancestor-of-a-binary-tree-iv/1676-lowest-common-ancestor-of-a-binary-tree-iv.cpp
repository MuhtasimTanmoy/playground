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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto left = lca(root->left, p, q);
        auto right = lca(root->right, p, q);
        if (left && right) return root;
        else return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        TreeNode* res = nodes[0];
        for(int i = 1; i < size(nodes); i++)
            res = lca(root, res, nodes[i]);
        return res;
    }
};