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
// class Solution {
    
//     vector<TreeNode*> res;
    
//     bool check(TreeNode* l, TreeNode* r) {
//         if (!l && !r) return true;
//         if (!l || !r) return false;
//         auto ltree = check(l->left, r->left), rtree = check(l->right, r->right);
//         return (l->val == r->val) && ltree && rtree;
//     }
    
//     void traverse(TreeNode* l, TreeNode* r) {
//          if (!l || !r) return;
//         if (l->val == r->val) {
//             if (check(l, r)) {
//                 res.push_back(l);
//                 traverse(l->left, r->left);
//                 traverse(l->right, r->right);
//             }
//         } else {
//             traverse(l, r->left);
//             traverse(l, r->right);
//             traverse(l->left, r);
//             traverse(l->right, r);
//         }
//     }
// public:
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         if (!root) return {};
//         traverse(root->left, root->right);
//         return res;
//     }
// };

class Solution {
    unordered_map<string, int> map;
    vector<TreeNode *> res;
    string postorder(TreeNode *root) {
        string lstr = "", rstr = "";
        if (root->left) lstr = postorder(root->left);
        if (root->right) rstr = postorder(root->right);
        string cstr = to_string(root->val) + " " + lstr + " " + rstr;
        if (++map[cstr] == 2) res.push_back(root);
        return cstr;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        postorder(root);
        return res;
    }
};