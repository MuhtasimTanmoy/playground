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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        function<TreeNode*(int, int, int, int)> go = 
            [&](auto in_left, auto in_right, 
                auto post_left, auto post_right) -> TreeNode* {
            
            if (in_left > in_right) return NULL;
            if (post_left > post_right) return NULL;
            
            auto curr = postorder[post_right];
            auto node = new TreeNode(curr);
            
            auto itr = in_left;
            while (inorder[itr] != curr) itr++;
            auto offset = post_left + itr - in_left;
            
            node->left = go(in_left, itr - 1, post_left, offset - 1);
            node->right = go(itr + 1, in_right, offset, post_right - 1);
            return node;
        };
        
        return go(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};