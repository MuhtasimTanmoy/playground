class Solution {
    int max_val = 0;
    pair<int, int> go(TreeNode* root) {
        if (!root) return {0, 0};
        int inc = 1, dcr = 1;
        if (root->left) {
            auto [_inc, _dcr] = go(root->left);
            if (root->val == root->left->val + 1) inc = _inc + 1;
            if (root->val == root->left->val - 1) dcr = _dcr + 1;
        }
        if (root->right) {
            auto [_inc, _dcr] = go(root->right);
            if (root->val == root->right->val + 1) inc = max(inc, _inc + 1);
            if (root->val == root->right->val - 1) dcr = max(dcr, _dcr + 1);
        }
        max_val = max(max_val, inc + dcr - 1);
        return {inc, dcr};
    }
public:
    int longestConsecutive(TreeNode* root) {
        go(root);
        return max_val;
    }
};