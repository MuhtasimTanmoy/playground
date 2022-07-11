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

// Failed attempt with level order traverse

// class Solution {
//     vector<int> boundary(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> rightAwaitingNodes;

//         queue<TreeNode*> q;
//         if (root) q.push(root);
        
//         while (!q.empty()) {
//             auto qLen = size(q);
//             for (int i = 0; i < qLen; i++) {
//                 auto item = q.front();
//                 q.pop();
                
//                 if (i == qLen - 1) rightAwaitingNodes.push(item);
//                 else if (i == 0 || (!item->left && !item->right)) 
//                     res.push_back(item->val);
                
//                 if (item->left) q.push(item->left);
//                 if (item->right) q.push(item->right);
//             }
//         }
        
//         while(!rightAwaitingNodes.empty()) {
//             auto item = rightAwaitingNodes.top();
//             rightAwaitingNodes.pop();
//             res.push_back(item->val);
//         }
        
//         return res;
//     }
// public:
//     vector<int> boundaryOfBinaryTree(TreeNode* root) {
//         return boundary(root);
//     }
// };


// 3 steps, root, left, leaves, right
// public class Solution {

//     public boolean isLeaf(TreeNode t) {
//         return t.left == null && t.right == null;
//     }

//     public void addLeaves(List<Integer> res, TreeNode root) {
//         if (isLeaf(root)) {
//             res.add(root.val);
//         } else {
//             if (root.left != null) {
//                 addLeaves(res, root.left);
//             }
//             if (root.right != null) {
//                 addLeaves(res, root.right);
//             }
//         }
//     }

//     public List<Integer> boundaryOfBinaryTree(TreeNode root) {
//         ArrayList<Integer> res = new ArrayList<>();
//         if (root == null) {
//             return res;
//         }
//         if (!isLeaf(root)) {
//             res.add(root.val);
//         }
//         TreeNode t = root.left;
//         while (t != null) {
//             if (!isLeaf(t)) {
//                 res.add(t.val);
//             }
//             if (t.left != null) {
//                 t = t.left;
//             } else {
//                 t = t.right;
//             }

//         }
//         addLeaves(res, root);
//         Stack<Integer> s = new Stack<>();
//         t = root.right;
//         while (t != null) {
//             if (!isLeaf(t)) {
//                 s.push(t.val);
//             }
//             if (t.right != null) {
//                 t = t.right;
//             } else {
//                 t = t.left;
//             }
//         }
//         while (!s.empty()) {
//             res.add(s.pop());
//         }
//         return res;
//     }
// }


// Preorder
class Solution {
    vector<int> res;
    void preorder(TreeNode *root, int left, int right) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        if (left) res.push_back(root->val);
        preorder(root->left, left, right && !root->right);
        preorder(root->right, left && !root->left, right);
        if (right) res.push_back(root->val);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        res.push_back(root->val);
        preorder(root->left, 1, 0);
        preorder(root->right, 0, 1);
        return res;
    }
};