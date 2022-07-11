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
    
    bool isLeaf(TreeNode* root) {
        if (!root->left && !root->right) return true;
        return false;
    }
    
    vector<vector<int>> extractedLeaves(TreeNode* root) {
        vector<vector<int>> result;
        while(root && !isLeaf(root)) {
            auto leaves = getLeaves(root);
            result.push_back(leaves);
        }
        if (root) result.push_back({root->val});
        return result;
    }
    
    vector<int> getLeaves(TreeNode* root) {
        vector<int> leaves;
        if (root) preorder(root, leaves);
        return leaves;
    }
    
    bool preorder(TreeNode* root, vector<int>& leaves) {
        
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return true;
        }
        
        auto isLeftLeaf = root->left ? preorder(root->left, leaves) : true;
        auto isRightLeaf = root->right ? preorder(root->right, leaves) : true;
        
        if (isLeftLeaf) root->left = NULL;
        if (isRightLeaf) root->right = NULL;
        
        return false;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        return extractedLeaves(root);
    }
};