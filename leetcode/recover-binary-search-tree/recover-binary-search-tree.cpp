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
    TreeNode* first,*second,*pr;
    void inorder(TreeNode* root) {
        
        if(!root) return;
        inorder(root->left);
        
        if(first == nullptr && pr->val > root->val) first=pr;
        if(first != nullptr && pr->val > root->val) second=root;
        
        pr=root;
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        pr = new TreeNode(INT_MIN); 
        inorder(root);
        swap(first->val,second->val); 
    }
};