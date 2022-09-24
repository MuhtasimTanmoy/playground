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
    void reverse(vector<TreeNode*> &li) {
        int left = 0, right = size(li) - 1;
        while (left < right) {
            auto cache = li[left]->val;
            li[left]->val = li[right]->val;
            li[right]->val = cache;
            left++; right--;
        }
    }
    
    void traverse(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q; q.push(root);
        bool isOdd = false;
        while (q.size()) {
            auto sz = q.size();
            vector<TreeNode*> li;
            for (int i = 0; i < sz; i++) {
                auto elem = q.front(); q.pop();
                if (isOdd) li.push_back(elem);
                if (elem->left) q.push(elem->left);
                if (elem->right) q.push(elem->right);
            }
            if (isOdd) reverse(li);
            isOdd = !isOdd;
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverse(root);
        return root;
    }
};