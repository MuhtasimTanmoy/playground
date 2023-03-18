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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        bool isEnd = false;
        while (q.size()) {
            auto n = q.size();
            while (n--) {
                auto top = q.front(); q.pop();
                
                if (top->left) {
                    if (isEnd) return false;
                    q.push(top->left);
                } else isEnd = true;
                
                if (top->right) {
                     if (isEnd) return false;
                    q.push(top->right); 
                } else isEnd = true;
            }
        }
        return true;
    }
};