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
    vector<int> res;
    void traverse(TreeNode* root) {
        int count = 0;
        TreeNode* alone;
        if (root->left) { 
            alone = root->left;
            traverse(root->left); 
            count++; 
        }
        if (root->right) { 
            alone = root->right;
            traverse(root->right); 
            count++; 
        }
        if (count == 1) res.push_back(alone->val);
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        if (root) traverse(root);
        return res;
    }
};