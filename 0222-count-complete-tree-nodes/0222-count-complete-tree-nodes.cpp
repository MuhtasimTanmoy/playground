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
    int countNodes(TreeNode* root) {
        int count = 0;
        function<int(TreeNode*)> traverse;
        traverse = [&](TreeNode* root) -> int {
            if (!root) return 0;
            auto left = traverse(root->left);
            auto right = traverse(root->right);
            return left + right + 1;
        };
        return traverse(root);
    }
};