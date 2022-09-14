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

/*
class Solution {
    bool isPalindrome(vector<int>& li) {
        int oddCount = 0, len = 0;
        for (auto count: li) if (count & 1) oddCount++;
        return oddCount <= 1;
    }
    
    int countPseudoPalindromicPaths(TreeNode* root, vector<int>& path) {
        if (!root) return 0;
        path[root->val]++;
        if (!root->left && !root->right) {
            auto res = isPalindrome(path) ? 1: 0;
            path[root->val]--;
            return res;
        }
        int left = countPseudoPalindromicPaths(root->left, path);
        int right = countPseudoPalindromicPaths(root->right, path);
        path[root->val]--;
        return left + right;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if (!root) return 0;
        vector<int> li(10, 0);
        return countPseudoPalindromicPaths(root, li);
    }
};

*/

class Solution {
    int countPseudoPalindromicPaths(TreeNode* root, int path) {
        if (!root) return 0;
        path ^= 1 << root->val;
        if (!root->left && !root->right) {
            auto res = ((path & (path - 1)) == 0) ? 1: 0;
            return res;
        }
        int left = countPseudoPalindromicPaths(root->left, path);
        int right = countPseudoPalindromicPaths(root->right, path);
        return left + right;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if (!root) return 0;
        return countPseudoPalindromicPaths(root, 0);
    }
};