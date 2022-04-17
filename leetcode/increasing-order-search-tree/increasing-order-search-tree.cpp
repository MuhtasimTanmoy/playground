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
    TreeNode* result = new TreeNode();
    TreeNode* itr = result;
    
    
    TreeNode* increasingBST(TreeNode* root) {
        if ( root == nullptr ) { return nullptr; }
        
        increasingBST(root->left);
        itr->right = root;
        root->left = nullptr;
        
        itr = itr->right;
        increasingBST(root->right);
        return result->right;
    }
};