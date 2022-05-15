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
    
    char convert(int a) {
        return static_cast<char>('a' + a);
    }
    
    string preorder(TreeNode* root, string soFar) {
        if (!root->left && !root->right) 
            return convert(root->val) + soFar;
        
        if (!root->right) return preorder(root->left, convert(root->val) + soFar);
        if (!root->left) return preorder(root->right, convert(root->val) + soFar);
        
        auto left = preorder(root->left, convert(root->val) + soFar);
        auto right = preorder(root->right, convert(root->val) + soFar);
            
        if (left < right) return left;
        else return right;
        
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        return preorder(root, "");
    }
};