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
    
    vector<vector<int>> traverse (TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        
        while (q.size()) {
            int qSize = size(q);
            vector<int> level;
            
            for(int i = 0; i < qSize; i++) {
                auto elem = q.front(); q.pop();
                level.push_back(elem->val);
                
                if (elem->left) q.push(elem->left);
                if (elem->right) q.push(elem->right);
            }
            res.push_back(level);
        }
        return res;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        auto res = traverse(root);
        bool lvl = false;
        for (auto &v: res) {
            if (lvl) reverse(v.begin(), v.end());
            lvl = !lvl;
        }
        return res;
    }
};