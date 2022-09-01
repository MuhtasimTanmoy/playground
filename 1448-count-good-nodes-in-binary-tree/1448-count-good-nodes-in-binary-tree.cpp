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

// BFS Based
/*
class Solution {
    int counter = 0;
    void traverse(TreeNode* root, int maxSoFar) {
        if (!root) return;
        if (root->val >= maxSoFar) {
            maxSoFar = root->val;
            counter++;
        }
        if (root->left) traverse(root->left, maxSoFar);
        if (root->right) traverse(root->right, maxSoFar);
    }
public:
    int goodNodes(TreeNode* root) {
        traverse(root, INT_MIN);
        return counter;
    }
};


class Solution {
    int traverse(TreeNode* root, int maxSoFar) {
        int goodCount = 0;
        if (!root) return goodCount;
        if (root->val >= maxSoFar) {
            maxSoFar = root->val;
            goodCount++;
        }
        goodCount += traverse(root->left, maxSoFar);
        goodCount += traverse(root->right, maxSoFar);
        return goodCount;
    }
public:
    int goodNodes(TreeNode* root) {
        return traverse(root, INT_MIN);
    }
};
*/

class Solution {
public:
    int goodNodes(TreeNode* root) {
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, root->val));
        
        int res = 0;
        while (!stk.empty()) {
            auto top = stk.top(); stk.pop();
            int maxSoFar = top.second;
            if (top.first->val >= maxSoFar) {
                res++;
                maxSoFar = top.first->val;
            }
            if (top.first->right) stk.push(make_pair(top.first->right, maxSoFar));
            if (top.first->left) stk.push(make_pair(top.first->left, maxSoFar));
        }
        return res;
    }
};