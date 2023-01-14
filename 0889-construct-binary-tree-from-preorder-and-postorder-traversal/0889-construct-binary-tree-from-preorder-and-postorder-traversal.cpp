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
    int preIndex = 0, posIndex = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        auto root = new TreeNode(preorder[preIndex++]);
        if (root->val != postorder[posIndex])
            root->left = constructFromPrePost(preorder, postorder);
        if (root->val != postorder[posIndex])
            root->right = constructFromPrePost(preorder, postorder);
        posIndex++;
        return root;
    }
};