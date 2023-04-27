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


struct NodeWrapper {
    TreeNode* inner = NULL;
    int sibling_val_sum = 0;
    NodeWrapper(TreeNode* inner, int sibling_val_sum): inner(inner), sibling_val_sum(sibling_val_sum) {}
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<NodeWrapper*> q{ new NodeWrapper(root, root->val) };
        
        while (q.size()) {
            int sum = 0;
            for (auto w: q) sum += w->inner->val;
            
            vector<NodeWrapper*> t;
            for (auto w: q) {
                auto n = w->inner; int total = w->sibling_val_sum;
                n->val = sum - total;
                
                auto sum = (n->left ? n->left->val: 0) + (n->right ? n->right->val: 0);
                
                if (n->left) t.push_back(new NodeWrapper(n->left, sum));
                if (n->right) t.push_back(new NodeWrapper(n->right, sum));
            }
            q = t;
        }
        return root;
    }
};