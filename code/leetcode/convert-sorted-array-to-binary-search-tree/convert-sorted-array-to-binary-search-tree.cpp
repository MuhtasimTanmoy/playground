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
    
    TreeNode* toBST(int start, int end, vector<int>& nums) {
        if (start > end ) return nullptr;
        int mid = (start+end) >> 1;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = toBST(start, mid-1, nums);
        node->right = toBST(mid+1, end, nums);
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(0, size(nums)-1, nums);
    }
};