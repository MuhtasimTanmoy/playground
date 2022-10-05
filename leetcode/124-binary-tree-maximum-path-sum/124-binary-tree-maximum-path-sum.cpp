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
    int maxSum = INT_MIN;
    int traverse(TreeNode* root) {
        if (!root) return 0;
        auto leftSum = traverse(root->left);
        auto rightSum = traverse(root->right);
        auto total = max(leftSum, 0) + max(rightSum, 0) + root->val;
        maxSum = max(maxSum, total);
        return max(max(leftSum, 0), max(rightSum, 0)) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root) traverse(root);
        return maxSum;
    }
};

//      [5,
//    4,     8,
//   11, null,      13,        4,
// 7,  2,         ,null,1]