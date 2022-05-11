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
    bool hasPath(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (targetSum == root->val && !root->left && !root->right) return true;
        return hasPath(root->left, targetSum - root->val) 
            ||  hasPath(root->right, targetSum - root->val);
    }
    
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return hasPath(root, targetSum);
    }
};