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
    void go(TreeNode* r, int target, TreeNode* p, bool left) {
        if (!r) return;
        
        go(r->left, target, r, true);
        go(r->right, target, r, false);
        
        if (p && r->val == target && !r->left && !r->right) 
            if (left) p->left = NULL; 
            else p->right = NULL;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* r, int target) {
        go(r, target, NULL, false);
        if (r->val == target && !r->left && !r->right) return NULL;
        else return r;
    }
};