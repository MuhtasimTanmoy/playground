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
    string traverse(TreeNode* r, string prev = "") {
        char key = 'a' + r->val;
        auto node_str = key + prev;
        if (!r->left && !r->right) return node_str;
        
        if (!r->left) return traverse(r->right, node_str);
        if (!r->right) return traverse(r->left, node_str);
        return min(traverse(r->right, node_str), traverse(r->left, node_str));
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        return traverse(root, "");
    }
};