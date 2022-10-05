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
    int subTreeCount = 0;
    bool countSubTree(TreeNode* root, int parentVal) {
        if (!root) return true;
        
        auto isSameValLeft = countSubTree(root->left, root->val);
        auto isSameValRight = countSubTree(root->right, root->val);
        
        if (isSameValLeft == isSameValRight && isSameValRight) {
            subTreeCount++;
            return root->val == parentVal;
        } else return false;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root) countSubTree(root, -1);
        return subTreeCount;
    }
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//     int subTreeCount = 0;
//     enum ChildMatchState { valueEqual, nilEqual, notEqual};
    
//     ChildMatchState countSubTree(TreeNode* root, int parentVal) {
//         if (!root) return nilEqual;
        
//         auto isSameValLeft = countSubTree(root->left, root->val);
//         auto isSameValRight = countSubTree(root->right, root->val);
        
//         if (isSameValLeft == notEqual || isSameValRight == notEqual) return false;
        
//         switch ({isSameValLeft, isSameValRight}) {
//             case {nilEqual, nilEqual}:
//                 subTreeCount++;
//                 return root->val == parentVal ? valueEqual: notEqual;
//             case {valueEqual, nilEqual}:
                
//             case {nilEqual, valueEqual}:  
                
//             case {valueEqual, valueEqual}:
//                 subTreeCount++;
//                 return root->val == parentVal ? valueEqual: notEqual;
//         }
//     }
// public:
//     int countUnivalSubtrees(TreeNode* root) {
//         if (root) countSubTree(root, -1);
//         return subTreeCount;
//     }
// };