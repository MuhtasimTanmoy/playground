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
// public:
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         vector<int> root1Leafs, root2Leafs;
//         function<void(TreeNode*, int)> go = [&](auto node, auto type) {
//             if (!node) return;
//             if (!node->left && !node->right) {
//                 if (type) root2Leafs.push_back(node->val);
//                 else root1Leafs.push_back(node->val);
//             }
//             go(node->left, type);
//             go(node->right, type);
//         };
//         go(root1, 0);
//         go(root2, 1);
//         if (root1Leafs.size() != root2Leafs.size()) return false;
//         for (int i = 0; i < root1Leafs.size(); i++) 
//             if (root1Leafs[i] != root2Leafs[i])
//                 return false;
//         return true;
//     }
// };


class Solution {
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string str1 = "", str2 = "";
        preorder(root1, str1);
        preorder(root2, str2);
        return str1 == str2;
    }
    void preorder(TreeNode *root, string &str) {
        
        if (!root->left && !root->right) 
            str += (root->val);
        
        if (root->left) 
            preorder(root->left, str);
        
        if (root->right) 
            preorder(root->right, str);
    }
};