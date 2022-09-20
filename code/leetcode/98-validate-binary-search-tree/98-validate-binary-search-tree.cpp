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
    bool isValidBST(TreeNode* root, long left = LONG_MIN, long right = LONG_MAX) {
        
        if (!root) return true;
        
        if (root->left)
            if (root->left->val >= root->val 
                || root->left->val <= left) return false;
        
        if (root->right)
            if (root->right->val <= root->val 
                || root->right->val >= right) return false;
        
        return isValidBST(root->left, left, root->val) 
            && isValidBST(root->right, root->val, right);
    }
};