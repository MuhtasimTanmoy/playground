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
    
     vector<int> morrisTraversal(TreeNode* root) {
        
        vector<int> result;
        TreeNode* current = root;
        
        while (current) {
            
            if (current->left == nullptr) {
                
                result.push_back(current->val);
                current = current->right;
                
            } else {
                
                TreeNode* predecessor = current->left;
                
                while (predecessor->right != current && predecessor->right) 
                    predecessor = predecessor->right;
                
                if (predecessor->right) {
                    predecessor->right = nullptr;
                    current = current->right;
                } else {
                    predecessor->right = current;
                    result.push_back(current->val);
                    current = current->left;
                }
            } 
        }
        return result;
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        return morrisTraversal(root);
    }
};