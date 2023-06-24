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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isOdd = false;
        while (q.size()) {
            queue<TreeNode*> temp;
            vector<TreeNode*> store;
            auto n = q.size();
            for (int i = 0; i < n; i++) {
                auto n = q.front(); q.pop();
                if (isOdd) store.push_back(n);
                if (n->left)
                    temp.push(n->left);
                if (n->right) 
                    temp.push(n->right);
            }
            if (isOdd)
                for (int i = 0; i < n / 2; i++)
                    swap(store[i]->val, store[n - 1 - i]->val);
            swap(q, temp);
            isOdd = !isOdd;
        }
        return root;
    }
};