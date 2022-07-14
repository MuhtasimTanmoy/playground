/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
//     TreeNode* traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root) return NULL;
//         if (root == p || root == q) return root;
//         auto foundFromLeft = traverse(root->left, p, q);
//         auto foundFromRight = traverse(root->right, p, q);
//         if (foundFromLeft && foundFromRight) return root;
//         if (foundFromLeft || foundFromRight) if (root == p || root == q) return root;
//         if (foundFromLeft) return foundFromLeft;
//         if (foundFromRight) return foundFromRight;
//         return NULL;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return traverse(root, p, q);
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;
        while(true) {
            if (res->val > p->val && res->val > q->val) res = res->left;
            else if (res->val < p->val && res->val < q->val) res = res->right;
            else break;
        }
        return res;
    }
};

// class Solution {
// public:
//     TreeNode* lcs(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root->val > p->val && root->val > q->val) { return lcs(root->left, p, q); }
//         else if (root->val < p->val && root->val < q->val) { return lcs(root->right, p, q); }
//         else { return root; }
//     }
    
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return lcs(root, p, q);
//     }
// };