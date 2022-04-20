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
class BSTIterator {
    stack<TreeNode*> stack;
    
    void bootstrap(TreeNode* root) {
        while ( root -> left != nullptr ) {
            stack.push(root -> left);
            root = root->left; 
        }
    }
    
    void process(TreeNode* root) {
       if ( root->right == nullptr ) {
           if (!stack.empty()) stack.pop();
       } else {
           stack.pop();
           stack.push( root->right);
           bootstrap(root->right);
       }
    }
        
public:
    BSTIterator(TreeNode* root) {
        stack.push(root);
        bootstrap(root);
    }
    
    int next() {
        TreeNode* node = stack.top();
        int result = node->val;
        process(node);
        return result;
    }
    
    bool hasNext() {
        if (stack.empty()) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
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
// class BSTIterator {
//     stack<TreeNode*> stack;
    
// //     void process(TreeNode* root) {
// //         if ( root -> left != nullptr ) {
// //             stack.push(root -> left);
// //             return;
// //         }
        
// //         while(stack.top() -> right == nullptr && !stack.empty()) stack.pop();
// //         if (stack.empty()) return;
// //         stack.push(stack.top() -> right);
// //     }
    
//     void process(TreeNode* root) {
//         if ( root -> left != nullptr ) {
//             stack.push(root -> left);
//             return;
//         }
        
//         while(stack.top() -> right == nullptr && !stack.empty()) stack.pop();
//         if (stack.empty()) return;
//         stack.push(stack.top() -> right);
//     }
// public:
//     BSTIterator(TreeNode* root) {
//         stack.push(root);
//     }
    
//     int next() {
//         TreeNode* node = stack.top();
//         int result = node->val;
//         process(node);
//         return result;
//     }
    
//     bool hasNext() {
//         if (stack.empty()) return false;
//         else return true;
//     }
// };
