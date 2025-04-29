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
    TreeNode* go(vector<int>& N, int l, int r) {
        if (l > r) return NULL;
        if (l == r) return new TreeNode(N[l]);
        auto m = (l + r) / 2;
        auto rt = new TreeNode(N[m]);
        rt->left = go(N, l, m - 1);
        rt->right = go(N, m + 1, r);
        return rt;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& N) {
        return go(N, 0, N.size() - 1);
    }
};