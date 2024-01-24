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
    vector<TreeNode*> res;
    unordered_set<int> bag;
    bool go(TreeNode* r) {
        if (!r) return false;
        
        auto should_delete = bag.count(r->val);
        auto is_l = go(r->left), is_r = go(r->right);
        
        if (is_l) r->left = NULL;
        if (is_r) r->right = NULL;
        
        if (should_delete) {
            if (r->left) res.push_back(r->left);
            if (r->right) res.push_back(r->right);
        }
        return should_delete;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto i: to_delete) bag.insert(i);
        if (!bag.count(root->val)) res.push_back(root);
        go(root);
        return res;
    }
};