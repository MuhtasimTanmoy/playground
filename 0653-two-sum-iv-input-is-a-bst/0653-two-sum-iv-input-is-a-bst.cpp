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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> bag;
        function<bool(TreeNode*)> go = [&](TreeNode* node) -> bool {
            if (!node) return false;
            if (bag.count(node->val)) return true;
            bag.insert(k-node->val);
            return go(node->left) || go(node->right);
        };
        return go(root);
    }
};