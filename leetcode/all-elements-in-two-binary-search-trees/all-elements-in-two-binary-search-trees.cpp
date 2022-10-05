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

// o(n)
class Solution2 {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode *> sk1, sk2;
        vector<int> res;
        while (1) {
            while (root1) {
                sk1.push_back(root1);
                root1 = root1->left;
            }
            while (root2) {
                sk2.push_back(root2);
                root2 = root2->left;
            }
            if (!sk1.size() && !sk2.size()) {
                break;
            }
            TreeNode *now1 = sk1.size() ? sk1.back() : NULL;
            TreeNode *now2 = sk2.size() ? sk2.back() : NULL;
            if (!now1 || now1 && now2 && now1->val > now2->val) {
                res.push_back(now2->val);
                sk2.pop_back();
                root2 = now2->right;
            } else if (!now2 || now1 && now2 && now1->val <= now2->val) {
                res.push_back(now1->val);
                sk1.pop_back();
                root1 = now1->right;
            }
        }
        return res;
    }
};