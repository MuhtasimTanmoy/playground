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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        optional<int> firstVal;
        while (q.size()) {
            int sz = q.size(); firstVal = nullopt;
            for (int i = 0; i < sz; i++) {
                auto elem = q.front(); q.pop();
                if (!firstVal) firstVal = elem->val;
                if (elem->left) q.push(elem->left);
                if (elem->right) q.push(elem->right);
            }
        }
        return *firstVal;
    }
};