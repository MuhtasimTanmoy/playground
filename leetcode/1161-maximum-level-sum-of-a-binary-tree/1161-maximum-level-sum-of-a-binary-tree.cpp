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
        vector<TreeNode*> q{root};
        int max_sum = INT_MIN, level = 1, curr_level = 1;
        while (q.size()) {
            int n = q.size(), sum = 0;
            vector<TreeNode*> temp;
            for (int i = 0; i < n; i++) {
                auto elem = q.back(); q.pop_back();
                sum += elem->val;
                if (elem->left) temp.push_back(elem->left);
                if (elem->right) temp.push_back(elem->right);
            }
            if (sum > max_sum) 
                level = curr_level, max_sum = sum;
            swap(temp, q);
            curr_level++;
        }
        return level;
    }
};