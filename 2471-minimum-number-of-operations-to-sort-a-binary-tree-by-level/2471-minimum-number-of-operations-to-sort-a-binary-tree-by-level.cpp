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
    int minimumOperations(TreeNode* root) {
        int res = 0;
        vector<TreeNode*> q{root};
        while(q.size()) {
            vector<TreeNode*> q1;
            vector<int> vals, ids(q.size());
            for (auto n: q) {
                vals.push_back(n->val);
                if (n->left) q1.push_back(n->left);
                if (n->right) q1.push_back(n->right);
            }
            
            iota(begin(ids), end(ids), 0);
            sort(begin(ids), end(ids), [&](int i, int j) { return vals[i] < vals[j]; });
            for (int i = 0; i < ids.size(); ++i) 
                for (; ids[i] != i; ++res)
                    swap(ids[i], ids[ids[i]]);
            swap(q, q1);
        }
        return res;
    }
};