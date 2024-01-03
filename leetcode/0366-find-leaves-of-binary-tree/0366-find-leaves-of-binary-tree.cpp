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
// class Solution {
//     map<int, vector<int>> mp;
//     int go(TreeNode* rt) {
//         if (!rt->left && !rt->right) {
//             mp[0].push_back(rt->val);
//             return 0;
//         }
//         auto l = rt->left ? go(rt->left): -1, r = rt->right ? go(rt->right): -1;
//         auto level = max(l, r) + 1;
//         mp[level].push_back(rt->val);
//         return level;
//     }
// public:
//     vector<vector<int>> findLeaves(TreeNode* root) {
//         vector<vector<int>> res;
//         go(root);
//         for (auto [_, r]: mp) res.push_back(r);
//         return res;  
//     }
// };


// class Solution {
// private:
//     int dfs(TreeNode* root, vector<vector<int>>& res){
//         if(!root) return 0;
//         int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
//         if(level > (int)res.size()) res.push_back(vector<int>());
//         res[level - 1].push_back(root->val);
//         return level;
//     }
// public:
//     vector<vector<int>> findLeaves(TreeNode* root) {
//         vector<vector<int>> res;
//         dfs(root, res);
//         return res;
//     }
// };


class Solution {
private:
    vector<vector<int>> solution;
public:
    int getHeight(TreeNode *root) {
        if (!root) return -1;

        int leftHeight = getHeight(root->left),
            rightHeight = getHeight(root->right);
        
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        if (solution.size() == currHeight) 
            solution.push_back({});

        solution[currHeight].push_back(root->val);
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        solution.clear();
        getHeight(root);
        return solution;
    }
};