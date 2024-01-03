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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> track;
        function<void(TreeNode*, int, int)> go = [&](auto r, auto i, auto lvl) {
            if (!r) return;
            track[i][lvl].push_back(r->val);
            go(r->left, i - 1, lvl + 1);
            go(r->right, i + 1, lvl + 1);
        };
        go(root, 0, 0);
        
        vector<vector<int>> res;
        for (auto [_, val]: track) {
            res.push_back({});
            for (auto [_, vals]: val) {
                sort(vals.begin(), vals.end());
                for (auto v: vals) res.back().push_back(v);
            }
        }
        return res;
    }
};