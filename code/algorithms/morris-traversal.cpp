// There is a clever way to perform an in-order traversal using only linear 
// time and constant space, first described by J. H. Morris in his 1979 paper 
// "Traversing Binary Trees Simply and Cheaply". In general, the recursive and 
// iterative stack methods sacrifice linear space for the ability to return to 
// a node after visiting its left subtree. The Morris traversal instead exploits 
// the unused null pointer(s) of the tree's leaves to create a temporary link out 
// of the left subtree, allowing the traversal to be performed using only constant 
// additional memory. To apply it to this problem, we can simply swap all "left" and 
// "right" references, which will reverse the traversal.

class Solution {
    
    vector<int> morrisTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;
        
        while (current)
            if (current->left == nullptr) {
                result.push_back(current->val);
                current = current->right;
            } else {
                TreeNode* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) 
                    predecessor = predecessor->right;
                
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        return result;
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return morrisTraversal(root);
    }
};