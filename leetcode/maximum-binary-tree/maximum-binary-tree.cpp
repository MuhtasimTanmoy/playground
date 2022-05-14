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
    
    TreeNode* build(vector<int>& nums, int start, int end) {
        
        int maxIndex = 0;
        int maxNum = INT_MIN;
        
        for(int i = start; i <= end; i++) 
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxIndex = i;
            }
        
        if (maxNum == INT_MIN) return nullptr;
        
        TreeNode* root = new TreeNode(maxNum);
        root->left = build(nums, start, maxIndex - 1);
        root->right = build(nums, maxIndex + 1, end);
        return root;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, size(nums) - 1);
    }
};