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


class Solution {
    double diffMin = 10000;
    int res = 0;
public:
    int closestValue(TreeNode* root, double target) {
        if (!root) return 0;
        
        auto diff = abs(root->val - target);
        if (diff < diffMin) {
            diffMin = diff;
            res = root->val;
        }
        
        closestValue(root->left, target);
        closestValue(root->right, target);
        return res;
    }
};
 */

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double closest = root-> val;
        while (root) {
            auto val = root-> val;
            closest = abs(val - target) < abs(closest - target) ? val: closest;
            root = target > val ? root->right: root->left;
        }
        return closest;
    }
};