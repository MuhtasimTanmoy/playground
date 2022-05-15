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
    int sumOfDeepestLeaves = 0;
    
    int currentDeepestLevel = 0;
    void preorder(TreeNode* root, int level) {
                
        if (!root->left && !root->right) 
            if (level == currentDeepestLevel) 
                sumOfDeepestLeaves += root->val;
            else if ( level > currentDeepestLevel ) {
                currentDeepestLevel = level;
                sumOfDeepestLeaves = root->val;
            }
                
        if (root->left) preorder(root->left, level + 1);
        if (root->right) preorder(root->right, level + 1);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        preorder(root, 0);
        return sumOfDeepestLeaves;
    }
};