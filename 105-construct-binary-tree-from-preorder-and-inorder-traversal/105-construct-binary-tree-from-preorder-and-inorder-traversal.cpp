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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMapping;
        for(int i = 0; i < size(inorder); i++) inorderMapping[inorder[i]] = i;
        
        int idx = 0;
        function<TreeNode*(int, int)> traverse = [&](int left, int right) -> TreeNode* {
            if (left > right) return NULL;
            
            auto root = new TreeNode(preorder[idx++]);
            auto boundary = inorderMapping[root->val];
            
            root->left = traverse(left, boundary - 1);
            root->right = traverse(boundary + 1, right);
            return root;
        };
        return traverse(0, size(preorder) - 1);
    }
};