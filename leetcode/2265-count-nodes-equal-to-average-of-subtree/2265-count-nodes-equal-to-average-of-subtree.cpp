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
    int res = 0;
    
    pair<int, int> go(TreeNode* root) {
        if (!root) return {0, 0};
        auto [l_sum, l_count] = go(root->left);
        auto [r_sum, r_count] = go(root->right);
        
        pair<int, int> now = {l_sum + r_sum + root->val, l_count + r_count + 1};
        if ((now.first / now.second == root->val)) res++;
        return now;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        go(root);
        return res;
    }
};