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
    multiset<int> l;
    int res = 0;
    void go(TreeNode* r) {
        if (!r) return;
        l.insert(r->val);
        if (l.size() > 1) {
            auto diff = abs(*l.begin() - *prev(l.end()));
            res = max(res, diff);
        }
        go(r->left);
        go(r->right);
        l.erase(l.find(r->val));
    }
public:
    int maxAncestorDiff(TreeNode* r) {
        go(r);
        return res;
    }
};