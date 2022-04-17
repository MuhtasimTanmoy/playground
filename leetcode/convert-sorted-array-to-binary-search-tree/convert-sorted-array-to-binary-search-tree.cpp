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
    
    TreeNode* dfs(vector<int>& nums, int start, int end) {
        if ( start > end ) { return nullptr; } 
        int mid = (start+end) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dfs(nums, start, mid-1);
        node->right = dfs(nums, mid+1, end);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, size(nums)-1 );
    }
};