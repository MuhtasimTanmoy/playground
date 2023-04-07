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
    // sum, count, res
    array<int, 3> go(TreeNode* root) {
        if (!root) return {0, 0, 0};
        
        if (root->left == NULL && root->right == NULL) 
            return {root->val, 1, 1};
        
        auto l_meta = go(root->left),
             r_meta = go(root->right);
        
        int sum = l_meta[0] + r_meta[0] + root->val,
            count = l_meta[1] + r_meta[1] + 1,
            is_match = (sum / count) == root->val,
            res = l_meta[2] + r_meta[2] + is_match;
        
        return {sum, count, res};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        return go(root)[2];
    }
};