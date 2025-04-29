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
    vector<int> N;
    void traverse(TreeNode* r) {
        if (!r) return;
        traverse(r->left);
        N.push_back(r->val);
        traverse(r->right);
    }
    
    TreeNode* go(int l, int r) {
        if (l > r) return NULL;
        if (l == r) return new TreeNode(N[l]);

        auto m = (l + r) / 2;
        auto rt = new TreeNode(N[m]);
        rt->left = go(l, m - 1);
        rt->right = go(m + 1, r);
        return rt;
    }
public:
    TreeNode* balanceBST(TreeNode* r) {
        traverse(r);
        return go(0, N.size() - 1);
    }
};