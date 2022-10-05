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
        if (!root) return;
        queue<TreeNode*> li;
        li.push(root);
        while (li.size()) {
            auto sizeOfList = li.size();
            vector<int> levelNodes;
            for (int i = 0; i < sizeOfList; i++) {
                auto curr = li.front();
                li.pop();
                levelNodes.push_back(curr->val);
                if (curr->left) li.push(curr->left);
                if (curr->right) li.push(curr->right);
            }
            res.push_back(levelNodes);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, res);
        return res;
    }
};