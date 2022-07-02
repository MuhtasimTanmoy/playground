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
     bool traverse(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        
        while(!q.empty()) {
            int qSize = size(q);
            unordered_set<int> level;
            
            for(int i = 0; i < qSize; i++) {
                auto elem = q.front();
                level.insert(elem->val);
                q.pop();
                
                if (elem->left) q.push(elem->left);
                if (elem->right) q.push(elem->right);
                if (elem->left && elem->right) {
                    if (elem->left->val == x && elem->right->val == y) return false;
                    if (elem->left->val == y && elem->right->val == x) return false;
                }
            }
            
            if (level.count(x) && level.count(y)) return true;
        }
        return false;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        return traverse(root, x, y);
    }
};