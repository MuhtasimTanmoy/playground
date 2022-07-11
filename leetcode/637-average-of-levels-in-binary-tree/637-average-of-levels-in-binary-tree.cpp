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
     bool traverse(TreeNode* root, vector<double>& res) {
        queue<TreeNode*> q;
        if(root) q.push(root);
         
        while(!q.empty()) {
            int qSize = size(q);
            double addition = 0;
            double count = 0;
            for(int i = 0; i < qSize; i++) {
                auto elem = q.front();
                addition += elem->val;
                count++;
                q.pop();
                
                if (elem->left) q.push(elem->left);
                if (elem->right) q.push(elem->right);
            }
            res.push_back(addition/count);
        }
        return false;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        traverse(root, res);
        return res;
    }
};