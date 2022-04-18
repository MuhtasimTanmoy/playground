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
    int result = 0;
    int index = 1;
    void kthSmall(TreeNode* root, int k) {
        if ( root == nullptr ) { return; }
        kthSmall(root->left, k);
        if (index == k ) result = root->val;
        index++;
        kthSmall(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        kthSmall(root, k);
        return result;
    }
};