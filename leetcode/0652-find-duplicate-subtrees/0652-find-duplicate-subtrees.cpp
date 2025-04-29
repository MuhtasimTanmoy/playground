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
//     unordered_map<int, TreeNode*> track;
//     vector<TreeNode*> res;

//     bool match(TreeNode* l, TreeNode* r) {
//         if (!r && !l) return true; else false;
//         if (l->val != r->val) return false;
//         return match(l->left, r->left) && match(l->right, r->right);
//     }

//     void insert(TreeNode* r) {
//         if (!r) return;
//         res.push_back(r);
//         insert(r->left);
//         insert(r->right);
//     }

//     void go(TreeNode* r) {
//         if (!r) return;
//         if (track.count(r->val)) {
//             auto pre = track[r->val];
//             if (match(r, pre)) insert(r);
//         } else
//             go(r->left),
//             go(r->right),
//             track[r->val] = r; 
//     }
// public:
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* r) {
//         go(r);
//         return res;
//     }
// };


class Solution {
    unordered_map<string, int> map;
    vector<TreeNode *> res;
    string postorder(TreeNode *root) {
        if (!root) return "-";
        auto val = to_string(root->val) + " " 
                   + postorder(root->left) + " " 
                   + postorder(root->right);
        if (++map[val] == 2) res.push_back(root);
        return val;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        postorder(root);
        return res;
    }
};