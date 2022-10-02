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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<TreeNode*> stk;
        TreeNode* traverse = root1;
        unordered_set<int> tracker;
        while(!stk.empty() || traverse) {
            while(traverse) {
                stk.push_back(traverse);
                traverse = traverse->left;
            }
            auto top = stk.back();
            stk.pop_back();
            tracker.insert(target-top->val);
            traverse = top->right;
        }
        traverse = root2;
        while(!stk.empty() || traverse) {
            while(traverse) {
                stk.push_back(traverse);
                traverse = traverse->left;
            }
            auto top = stk.back();
            stk.pop_back();
            if (tracker.count(top->val)) return true;
            traverse = top->right;
        }
        return false;
    }
};