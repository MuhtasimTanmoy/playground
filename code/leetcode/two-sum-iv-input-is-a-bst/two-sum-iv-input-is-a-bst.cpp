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
    unordered_set<int> keys;
    
    bool traverse(TreeNode* root, int k) {
        if (!root) return false;
        // if (root->val >= k) return false;
        
        if (keys.count(k - root->val)) return true;
        keys.insert(root->val);
        
        return traverse(root->left, k) 
            || traverse(root->right, k);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        return traverse(root, k);
    }
};