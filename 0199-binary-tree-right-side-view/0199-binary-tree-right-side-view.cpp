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
    vector<int> rightView(TreeNode* root) {
        queue<TreeNode*> stk;
        vector<int> result;
        
        if (root) stk.push(root);
        while(!stk.empty()) {
            auto sizeStk = size(stk);
            bool taken = false;
            
            for(int i = 0 ; i < sizeStk; i++) {
                auto item = stk.front();
                stk.pop();
                
                if (!taken) {
                    taken = true;
                    result.push_back(item->val);
                }
                
                if (item->right) stk.push(item->right);
                if (item->left) stk.push(item->left);
            }
        }
        return result;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        return rightView(root);
    }
};