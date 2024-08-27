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
    vector<int> res;
    void go(TreeNode* r) {
        if (!r) return;
        go(r->left);
        go(r->right);
        res.push_back(r->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        go(root);
        return res;
    }
};