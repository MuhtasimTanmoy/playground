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
    TreeNode* calc(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        auto mid = left + (right-left) / 2;
        auto elem = nums[mid];
        TreeNode* root = new TreeNode(elem);
        root->left = calc(nums, left, mid - 1);
        root->right = calc(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return calc(nums, 0, nums.size() - 1);
    }
};