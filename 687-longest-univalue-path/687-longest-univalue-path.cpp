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
    int res = 0;
    
    int longestUnivalue(TreeNode* root, int parentVal) {
        if (!root) return 0;
        auto leftMatchCount = longestUnivalue(root->left, root->val);
        auto rightMatchCount = longestUnivalue(root->right, root->val);
        
        auto ifTriangle = leftMatchCount + rightMatchCount;
        res = max(res, ifTriangle);
        
        auto ifLine = max(leftMatchCount, rightMatchCount);
        res = max(res, ifLine);
        
        return root->val == parentVal ? ifLine + 1: 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        longestUnivalue(root, -1);
        return res;
    }
};