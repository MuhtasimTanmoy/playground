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
    
    int minTraverse(TreeNode* root, int depth) {        
        if (!root->left && !root->right) return depth + 1;
        
        if(!root->left) return minTraverse(root->right, depth + 1);
        if(!root->right) return minTraverse(root->left, depth + 1);
        
        return min( minTraverse(root->left, depth + 1), 
                    minTraverse(root->right, depth + 1));
    }
    
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return minTraverse(root, 0);
    }
};