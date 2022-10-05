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
     void traverse(TreeNode* root, vector<vector<int>>& res) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        
        while(!q.empty()) {
            int qSize = size(q);
            vector<int> level;
            
            for(int i = 0; i < qSize; i++) {
                auto elem = q.front();
                level.push_back(elem->val);
                q.pop();
                
                if (elem->left) q.push(elem->left);
                if (elem->right) q.push(elem->right);
            }
            res.push_back(level);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, result);
        return result;
    }
};