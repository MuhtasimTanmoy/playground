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
//     TreeNode* cache = NULL;
//     TreeNode* res = NULL;
// public:
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//         if (!root) return NULL;
//         if (p->right) {
//             auto item = p->right;
//             while (item->left) item = item->left;
//             return item;
//         }
//         traverse(root, p);
//         return res;
//     }
    
//     void traverse(TreeNode* root, TreeNode* p) {
//         if (!root) return;
//         traverse(root->left, p);
//         if (cache == p && !res) { 
//             cout<<root->val<<endl;
//             res = root; return; }
//         cache = root;
//         traverse(root->right, p);
//     }
// };


class Solution {
    TreeNode* cache = NULL;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            p = p->right;
            while (p->left) p = p->left;
            return p;
        }
        
        TreeNode* candidate = NULL;
        while (root != p)
            root = p->val > root->val ? root->right : (candidate = root)->left;
        return candidate;
    }
};