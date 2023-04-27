/**
 * Definition for a binary tree node.
 * struct C {
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
    int widthOfBinaryTree(TreeNode* root, unsigned long long res = 1) {
        vector<pair<TreeNode*, unsigned long long>> q {{root, 1}};
        while (q.size()) {
            vector<pair<TreeNode*, unsigned long long>> temp;
            auto n = q.size();
            for (int i = 0; i < n; i++) {
                auto e = q[i].first; auto w = q[i].second;                
                if (e->left)
                    temp.push_back({e->left, w * 2 - 1});
                if (e->right)
                    temp.push_back({e->right, w * 2});
            }
            auto w = (*q.rbegin()).second - (*q.begin()).second + 1;
            res = max(res, w);
            swap(temp, q);
        }
        return res;
    }
};