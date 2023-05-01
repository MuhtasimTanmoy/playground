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

// GETS TLE
/*
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        function<int(TreeNode*, int)> go = [&go](auto node, auto leave) {
            if (!node || node->val == leave) return 0;
            auto l = go(node->left, leave),
                 r = go(node->right, leave);
            return 1 + max(l, r);
        };
        vector<int> res;
        for (auto query: queries)
            res.push_back(go(root, query) - 1);
        return res;
    }
};
*/

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> ans; unordered_map<TreeNode*, int> hts; vector<int> res;
        function<int(TreeNode*)> height = [&](auto r) {
            return r ? (hts[r] = 1 + max(height(r->left), height(r->right))) : 0; 
        };
        function<void(TreeNode*,int,int)> dfs = [&](auto r, auto depth, auto mx) {
            if (!r) return;
            ans[r->val] = mx;
            dfs(r->right, depth + 1, max(mx, depth + hts[r->left]));
            dfs(r->left, depth + 1, max(mx, depth + hts[r->right]));
        };
        height(root); dfs(root, 0, 0);
        for (int& v: queries) res.push_back(ans[v]);
        return res;
    }
};
