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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return postorder(root, 0).first;
    }
    
    pair<TreeNode*, int> postorder(TreeNode *root, int depth) {
        if (!root) return make_pair(root, depth) ;
        auto left = postorder(root->left, depth + 1);
        auto right = postorder(root->right, depth + 1);
        int val = max(left.second, right.second) ;
        
        if (left.second == right.second) 
            return make_pair(root, val);
        else if (left.second > right.second) 
            return left;
        else 
            return right;
    }
};