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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return new TreeNode(val);
        if (depth == 1) {
            auto parent = new TreeNode(val);
            parent->left = root;
            return parent;
        }
        int currentDepth = 1;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            auto sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto elem = q.front(); q.pop();
                if (currentDepth == depth - 1) {
                        auto mid = new TreeNode(val);
                        mid->left = elem->left;
                        elem->left = mid;
      
                        auto midR = new TreeNode(val);
                        midR->right = elem->right;
                        elem->right = midR;
                } else {
                    if (elem->left) q.push(elem->left);
                    if (elem->right) q.push(elem->right);
                }
            }
            currentDepth++;
        }
        return root;
    }
};