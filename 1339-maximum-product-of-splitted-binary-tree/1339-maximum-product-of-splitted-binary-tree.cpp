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
    long long calc(TreeNode* root) {
        if (!root) return 0;
        auto val = root->val;
        val += calc(root->left);
        val += calc(root->right);
        return val;
    }
    
    long long total = 0, res = 0;
    int mod = 1e9 + 7;
    long long subtreeSum(TreeNode* root) {
        if (!root) return 0;
        
        auto lsum = subtreeSum(root->left);
        auto left = lsum * (total - lsum);
        res = max(left, res);
        
        auto rsum = subtreeSum(root->right);
        auto right = rsum * (total - rsum);
        res = max(right, res);
        
        return root->val + lsum + rsum;
    }
public:
    int maxProduct(TreeNode* root) {
        total = calc(root);
        auto _ = subtreeSum(root);
        return res % mod;
    }
};