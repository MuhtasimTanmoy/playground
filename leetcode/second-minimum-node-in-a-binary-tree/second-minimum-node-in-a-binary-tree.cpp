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
    set<int> bag;
    
    void kthSmall(TreeNode* root, int k) {
        if ( root == nullptr ) { return; }
        kthSmall(root->left, k);
        
        if ( bag.count(root->val) == 0 ) { 
            bag.insert(root->val);
            if ( size(bag) == k ) { return; }
        }
        
        kthSmall(root->right, k);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        kthSmall(root, 2);
        if ( size(bag) < 2 ) { return -1; }
        return vector<int>(bag.begin(), bag.end()).at(1);
    }
};

// Alternate

class Solution {
public:
    void dfs(TreeNode* root,set<int>&s){
        if(root == NULL)
            return;
        
        s.insert(root->val);
        dfs(root->left,s);
        dfs(root->right,s);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int>s;
        dfs(root,s);
        auto it = s.begin();
        it++;
        if(s.size() == 1)
            return -1;
        return *it;
    }
};