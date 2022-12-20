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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        stack<TreeNode*> s;
        TreeNode *curr = root;
        while (curr != NULL || s.size()) {
            while (curr !=  NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            if (curr->val >= low && curr->val <= high) res += curr->val;
            s.pop();
            curr = curr->right;
        }
        return res;
    }
};