/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// Failed Attempt
// class Solution {
//     bool traverse(ListNode* head, TreeNode* root) {
//         if (!head) return true;
//         if (!root) return false;
//         if (head->val == root->val)
//             return traverse(head->next, root->left) || traverse(head->next, root->right);
//         else
//             return traverse(head, root->left) || traverse(head, root->right);                             
//     }
// public:
//     bool isSubPath(ListNode* head, TreeNode* root) {
//         return traverse(head, root);
//     }
// };

// For this particular problem must 
class Solution {
public:
    bool check(ListNode *head,TreeNode *root) {
        if (!head) return true;
        if (!root) return false;
        
        if(root->val != head->val) return false;
        return check(head->next, root->left) || check(head->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};