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
    int idx = 0;
    TreeNode* traverse(int left, int right, vector<int>& preorder, unordered_map<int, int>& map) {
        if (left > right) return NULL;
        auto root = new TreeNode(preorder[idx++]);
        auto boundary = map[root->val];
        root->left = traverse(left, boundary - 1, preorder, map);
        root->right = traverse(boundary + 1, right, preorder, map);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMapping;
        for(int i = 0; i < size(inorder); i++) inorderMapping[inorder[i]] = i;
        return traverse(0, size(preorder) - 1, preorder, inorderMapping);
    }
};