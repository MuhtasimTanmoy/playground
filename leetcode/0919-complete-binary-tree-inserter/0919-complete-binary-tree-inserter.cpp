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

// enum Direction {
//     left,
//     right
// };

// class CBTInserter {
//     TreeNode* root;
// public:
//     CBTInserter(TreeNode* root): root(root) {}
    
//     vector<Direction> get_path(int val) {
//         vector<Direction> to;
//         while (val != 1) {
//             auto is_odd = val & 1;
//             to.push_back(is_odd ? Direction::right: Direction::left);
//             val >>= 1;
//         }
//         reverse(to.begin(), to.end());
//         return to;
//     }
    
//     int insert(int val) {
//         auto path = get_path(val);
//         auto itr = root;
//         for (auto dir: path) 
//             if (dir == Direction::left) {
//                 if (!itr->left) {
//                     itr->left = new TreeNode(val);
//                     return itr->val;
//                 }
//                 itr = itr->left;
//             }
//             else {
//                 if (!itr->right) {
//                     itr->right = new TreeNode(val);
//                     return itr->val;
//                 }
//                 itr = itr->right;
//             }
//         return 0;
//     }
    
//     TreeNode* get_root() {
//         return root;
//     }
// };

class CBTInserter {
private:
    TreeNode* root = nullptr;
public:
    CBTInserter(TreeNode* root) :root(root) {}
    
    int insert(int v) {
        queue<TreeNode*> q;
        q.emplace(root);
        TreeNode* curr = nullptr;
        while (q.size()) {
            curr = q.front(), q.pop();
            if (curr->left == NULL) { 
                curr->left = new TreeNode(v); 
                curr->right = NULL;
                break; 
            }
            if (curr->right == NULL) { curr->right = new TreeNode(v); break; }
            if (curr->left) q.emplace(curr->left);
            if (curr->right) q.emplace(curr->right);
        }
        return curr->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};