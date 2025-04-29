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
    int min_dist = INT_MAX, pre = INT_MAX;
    void go(TreeNode* r) {
        if (!r) return;
        go(r->left);
        min_dist = min(min_dist, abs(pre - r->val));
        pre = r->val;
        go(r->right);
    }
public:
    int minDiffInBST(TreeNode* r) {
        go(r);
        return min_dist;
    }
};