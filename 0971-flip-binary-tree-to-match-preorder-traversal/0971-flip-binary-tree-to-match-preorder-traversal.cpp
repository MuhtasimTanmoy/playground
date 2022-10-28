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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flips;
        
        function<bool(TreeNode*, int&)> go = [&](TreeNode* node, int& index) -> bool {
            if (!node) return true;
            if (node->val != voyage[index++]) return false;
            if (node->left && node->left->val != voyage[index]) {
                flips.push_back(node->val);
                swap(node->left, node->right);
            }
            return go(node->left, index) && go(node->right, index);
        };
        
        
        int index = 0;
        auto canBe = go(root, index);
        return canBe ? flips: vector<int>{-1};
    }
};