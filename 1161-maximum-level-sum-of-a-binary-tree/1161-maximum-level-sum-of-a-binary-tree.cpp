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
        vector<TreeNode*> q {root};
        int maxSum = INT_MIN, minLevel = 0, currLevel = 0;
        while (q.size()) {
            vector<TreeNode*> local;
            int sum = 0; currLevel++;
            for (auto i: q) {
                sum += i->val;
                if (i->left) local.push_back(i->left);
                if (i->right) local.push_back(i->right);
            }            
            if (sum > maxSum) {
                maxSum = sum;
                minLevel = currLevel;
            }
            swap(q, local);
        }
        return minLevel;
    }
};