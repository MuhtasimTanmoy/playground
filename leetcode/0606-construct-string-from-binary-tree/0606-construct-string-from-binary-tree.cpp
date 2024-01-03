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
    void go(TreeNode* root) {
        if (!root) return;
        
        res += to_string(root->val);
        if (root->left || root->right) {
            res += "(";
            go(root->left);
            res += ")";
            
            if (root->right) {
                res += "(";
                go(root->right);
                res += ")";
            }
        }
    }
public:
    string tree2str(TreeNode* root) {
        go(root);
        return res;
    }
};