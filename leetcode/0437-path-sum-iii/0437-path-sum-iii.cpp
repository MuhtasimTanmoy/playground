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
    int result = 0, target = 0;
    void traverse(TreeNode* root, vector<long long> targetSums) {
        if ( !root ) return;
        
        for (auto &targetSum: targetSums) {
            if (root->val == targetSum) result++;
            targetSum -= root->val;
        }

        if (target == root->val) result++;
        targetSums.push_back(target - root->val);
        
        traverse(root->left, targetSums);
        traverse(root->right, targetSums);
        
        targetSums.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        traverse(root, {});
        return result;
    }
};