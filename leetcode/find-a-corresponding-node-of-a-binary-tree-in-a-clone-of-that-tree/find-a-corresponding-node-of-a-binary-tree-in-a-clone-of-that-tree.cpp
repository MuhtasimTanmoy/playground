/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original && !cloned) return nullptr;
        if (original == target) return cloned;
        
        auto left = getTargetCopy(original->left, cloned->left, target);
        auto right = getTargetCopy(original->right, cloned->right, target);
        
        return left == nullptr ? right : left;
    }
};