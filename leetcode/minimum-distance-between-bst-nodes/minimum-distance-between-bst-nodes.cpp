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
    int result = INT_MAX;
    int cache = INT_MAX;
    
    void inorder(TreeNode* root) {
        if ( root == nullptr ) { return; }
        inorder(root->left);
        result = min(abs(cache-root->val), result);
        cache = root->val;
        inorder(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return result;
    }
};