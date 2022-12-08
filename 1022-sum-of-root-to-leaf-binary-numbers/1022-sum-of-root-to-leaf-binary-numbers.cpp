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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        vector<int> li;
        function<void(TreeNode*, vector<int>)> go = [&](auto node, auto list) {
            if (!node) return;
            list.push_back(node->val);
            if (!node->left && !node->right) {
                int len = list.size();
                int res = 0;
                for (int i = 0; i < len; i++) {
                    auto elem = list[len - i - 1];
                    if (!elem) continue;
                    res += pow(2, i);
                }
                sum += res;
            }
            go(node->left, list);
            go(node->right, list);
            list.pop_back();
        };
        go(root, li);
        return sum;
    }
};