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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> l;
        l.push_back(root);
        int min_sum = INT_MIN, res = -1, index = 1;
        while (l.size()) {
            int n = l.size(), sum = 0;
            vector<TreeNode*> now;
            for (auto i = 0; i < n; i++) {
                sum += l[i]->val;
                if (l[i]->left) now.push_back(l[i]->left);
                if (l[i]->right) now.push_back(l[i]->right);
            }
            if (sum > min_sum) min_sum = sum, res = index;
            l = now;
            index++;
        }
        return res;
    }
};