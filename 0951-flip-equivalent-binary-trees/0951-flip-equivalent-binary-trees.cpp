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
    bool traverse(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (root1 == NULL || root2 == NULL) return false;
        if (root1->val != root2->val) return false;
        auto root1Val = root1 ? root1->left ? root1->left->val: -1 : -1;
        auto root2Val = root2 ? root2->left ? root2->left->val: -1 : -1;
        if (root1Val != root2Val) {
            swap(root1->left, root1->right);
        }
        return traverse(root1->left, root2->left) && traverse(root1->right, root2->right);
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        auto isPossible = traverse(root1, root2);
        return isPossible;
    }
};