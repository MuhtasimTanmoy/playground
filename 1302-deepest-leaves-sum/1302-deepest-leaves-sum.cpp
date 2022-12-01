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
    int deepestLeavesSum(TreeNode* root) {
        int deepCount = 0, deepSoFar = -1;
        function<void(TreeNode*, int)> go = [&](TreeNode* node, int depth) {
            if (!node) return;
            if (depth > deepSoFar) {
                deepCount = 0;
                deepSoFar = depth;
            }
            if (depth == deepSoFar) deepCount += node->val;
            go(node->left, depth + 1);
            go(node->right, depth + 1);
        };
        go(root, 0);
        return deepCount;
    }
};