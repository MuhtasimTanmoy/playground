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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> go = [&](TreeNode* n) {
            if (!n) return;
            if (n->left) go(n->left);
            res.push_back(n->val);
            if (n->right) go(n->right);
        };
        go(root);
        return res;
    }
};