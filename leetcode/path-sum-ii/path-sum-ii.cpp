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
    
    vector<vector<int>> result;
    void traverse(TreeNode* root, int targetSum, vector<int> list) {
        if(!root->left && !root->right) 
            if (targetSum == root->val) {
                list.push_back(root->val);
                result.push_back(list);
            }
        
        list.push_back(root->val);
        if (root->left) traverse(root->left, targetSum - root->val, list);
        if (root->right) traverse(root->right, targetSum - root->val, list);
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        traverse(root, targetSum, {});
        return result;
    }
};