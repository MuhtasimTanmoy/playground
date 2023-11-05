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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<TreeNode*> q {root};
        vector<int> res;
        while (q.size()) {
            int n = q.size(), max_now = INT_MIN;
            vector<TreeNode*> temp;
            for (auto i = 0; i < n; i++) {
                if (q[i]->left) temp.push_back(q[i]->left);
                if (q[i]->right) temp.push_back(q[i]->right);
                max_now = max(max_now, q[i]->val);
            }
            res.push_back(max_now);
            q = temp;
        }
        return res;
    }
};