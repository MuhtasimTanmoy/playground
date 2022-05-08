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
                    result.push_back(current->val);
                    current = current->right;
                } else {
                    predecessor->right = current;
                    current = current->left;
                }
            } 
        }
        return result;
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return morrisTraversal(root);
    }
};