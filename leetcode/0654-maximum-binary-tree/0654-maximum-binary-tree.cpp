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

// class Solution {
//     TreeNode* go(vector<int>& N, int l, int r) {
//         if (l > r) return NULL;
//         if (l == r) return new TreeNode(N[l]);

//         auto m = (l + r) / 2;
//         auto now = new TreeNode(N[m]);
//         now->left = go(N, l, m - 1);
//         now->right = go(N, m + 1, r);
//         return now;
//     }
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& N) {
//         int max_idx = -1;
//         for (auto i = 0, max_elem = 0; i < N.size(); i++) 
//             if (N[i] > max_elem) 
//                 max_elem = N[i], max_idx = i;

//         TreeNode* root = new TreeNode(N[max_idx]);
//         root->left = go(N, 0, max_idx - 1);
//         root->right = go(N, max_idx + 1, N.size() - 1);
//         return root;
//     }
// };


class Solution {
    TreeNode* build(vector<int>& nums, int l, int r) {
        int maxIndex = 0, maxNum = INT_MIN;
        for (int i = l; i <= r; i++) 
             if (nums[i] > maxNum) 
                maxNum = nums[i], maxIndex = i;
        
        if (maxNum == INT_MIN) return nullptr;

        TreeNode* root = new TreeNode(maxNum);
        root->left = build(nums, l, maxIndex - 1);
        root->right = build(nums, maxIndex + 1, r);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, size(nums) - 1);
    }
};