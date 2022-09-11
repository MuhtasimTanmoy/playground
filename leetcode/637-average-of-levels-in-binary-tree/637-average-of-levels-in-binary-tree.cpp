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
    void traverse(TreeNode* root, vector<double>& li) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto qSize = q.size();
            double movingAvg = 0;
            for (int i = 0; i < qSize; i++) {
                auto item = q.front(); q.pop();
                if (item->left) q.push(item->left);
                if (item->right) q.push(item->right);
                movingAvg = ( movingAvg * i + item->val ) / (i + 1);
            }
            li.push_back(movingAvg);
        }
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        traverse(root, res);
        return res;
    }
};