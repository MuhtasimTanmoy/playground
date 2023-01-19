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
//     TreeNode* sufficientSubset(TreeNode* root, int limit) {
//         if (!root) return 0;
//         auto left = sufficientSubset(root->left, limit);
//         auto right = sufficientSubset(root->right, limit);
        
//         if (left < limit) root->left = NULL, left = 0;
//         if (right < limit) root->right = NULL, right = 0;
        
//         return 
//     }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root->left == root->right)
            return root->val < limit ? NULL : root;
        if (root->left)
            root->left = sufficientSubset(root->left, limit - root->val);
        if (root->right)
            root->right = sufficientSubset(root->right, limit - root->val);
        return root->left == root->right ? NULL : root;
    }
};