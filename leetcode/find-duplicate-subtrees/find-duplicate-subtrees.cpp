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
    
    unordered_map<string, TreeNode*> checker;
    unordered_map<string, TreeNode*> res;
    
    string traverse(TreeNode* root) {
        if(!root) return "()";
        
        string s = to_string(root->val);
        s += "(" + traverse(root->left) + ")";
        s += "(" + traverse(root->right) + ")";
        
        if (checker.count(s)) res[s] = root;
        else checker[s] = root;
        
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        vector<TreeNode*> result;
        for(auto [str, node] : res) result.push_back(node);
        return result;
    }
};