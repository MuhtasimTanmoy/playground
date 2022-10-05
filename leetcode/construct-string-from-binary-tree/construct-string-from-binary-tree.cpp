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
    string res = "";
    
    void traverse(TreeNode* root) {
        res += to_string(root->val);
        
        if (root->left) {
            res += "(";
            traverse(root->left);
            res += ")";
        }
        
        if (root->right) {
            if (!root->left) res += "()";
            res += "(";
            traverse(root->right);
            res += ")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        traverse(root);
        return res;
    }
};