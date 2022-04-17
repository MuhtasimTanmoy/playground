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
    vector<int> result;
    
    void inorder(TreeNode* root1) {
        if (!root1) { return; }
        inorder(root1->left);
        result.push_back(root1->val);
        inorder(root1->right);
        
//         if (root1->left &&  root2->left) inorder(root1->left, root2->left);
//         else if (root1->left) inorder(root1->left, root2);
//         else if (root2->left) inorder(root1, root2->left);
        
//         result.push_back(min(root1->val, root2->val));
//         result.push_back(max(root1->val, root2->val));
        
//         if (root1->right &&  root2->right) inorder(root1->right, root2->right);
//         else if (root1->right) inorder(root1->right, root2);
//         else if (root2->right) inorder(root1, root2->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        inorder(root2);
        sort(begin(result), end(result));
        return result;
    }
};