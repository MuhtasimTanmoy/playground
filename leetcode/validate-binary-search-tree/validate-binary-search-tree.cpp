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
    bool isValidBST(TreeNode* root) {
        return preorder(root, LONG_MIN, LONG_MAX);
    }
    
    bool preorder(TreeNode *root, long long minv, long long maxv) {
        if (!root) 
            return true;
        
        if (root->val <= minv || root->val >= maxv) 
            return false;
        
        return preorder(root->left, minv, root->val) 
            && preorder(root->right, root->val, maxv);
    }
};