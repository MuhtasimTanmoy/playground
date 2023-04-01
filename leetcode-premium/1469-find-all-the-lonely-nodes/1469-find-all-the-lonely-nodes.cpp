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
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> go = [&](auto node) {
            if (!node) return;
            if (node->left && !node->right) res.push_back(node->left->val);
            if (!node->left && node->right) res.push_back(node->right->val);  
            go(node->left);
            go(node->right);
        };
        go(root);
        return res;
    }
};