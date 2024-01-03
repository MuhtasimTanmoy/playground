// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         vector<TreeNode*> stk;
//         stk.push_back(root);
//         while (stk.size()) {
//             if (stk.back()->left) {
//                 res.push_back(stk.back()->val);
//                 while (stk.back()->left) 
//                     stk.push_back(stk.back()->left),
//                     res.push_back(stk.back()->val);
//             }
//             if (stk.back()->right)
//                 stk.push_back(stk.back()->right);
//             else stk.pop_back();
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        while (root || stack.size()) {
            while (root) stack.push(root), root = root->left;
            root = stack.top(); stack.pop();
            
            res.push_back(root->val);
            root = root->right;
        }
        return res;        
    }
};