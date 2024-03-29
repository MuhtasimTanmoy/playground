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
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int, int> map; int preIdx = 0;
//         for (int i = 0; i < size(inorder); i++) map[inorder[i]] = i;
//         function<TreeNode*(int, int)> traverse = [&](int left, int right) -> TreeNode* {
//             if (left > right) return NULL;
//             auto root = preorder[preIdx++];
//             return new TreeNode(root, traverse(left, map[root] - 1), traverse(map[root] + 1, right));
//         };
//         return traverse(0, size(preorder) - 1);
//     }
// };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* last = NULL; // used for backtracking
        TreeNode* root = NULL;
        vector<TreeNode*> stack;
        for(int i = 0, j = 0; i < size(preorder);) {
            if (!stack.empty() && stack.back()->val == inorder[j]) {
                last = stack.back();
                stack.pop_back();
                j++;
            } else if (last) {
                last->right = new TreeNode(preorder[i++]);
                stack.push_back(last->right);
                last = NULL;
            } else {
                auto now = new TreeNode(preorder[i++]);
                if (!stack.empty()) stack.back()->left = now;
                else if (!root) root = now;
                stack.push_back(now);
            }
        }
        return root;
    }
};