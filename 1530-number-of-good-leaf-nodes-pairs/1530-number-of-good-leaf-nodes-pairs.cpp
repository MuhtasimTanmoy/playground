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
    int p = 0;
    vector<int> f(TreeNode * root,int dist) {
        vector<int> ans ;
        if (!root) return ans;
        auto left = f(root->left, dist);
        auto right = f(root->right, dist);
        
        if(!left.size() && !right.size()) {
            ans.push_back(1);
            return ans ;
        }
        
         for(int i = 0; i < left.size(); i++)
             for(int j = 0; j < right.size(); j++)
                 if(left[i] + right[j] <= dist)
                     p++;

        for(int i = 0; i < left.size(); i++)
            ans.push_back(left[i] + 1);
        
        for(int i = 0; i < right.size(); i++)
            ans.push_back(right[i]+1);
        
        return ans ;
    }
    
    int countPairs(TreeNode* root, int distance) {
        f(root,distance);
        return p ;
    }
};