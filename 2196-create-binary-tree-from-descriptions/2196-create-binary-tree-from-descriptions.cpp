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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> index;
        unordered_set<int> childs, parents;
        for (auto desc: descriptions) {
            auto parent = desc[0], child = desc[1], isLeft = desc[2];
            parents.insert(parent);
            childs.insert(child);
            
            if (index.count(parent) == 0) index[parent] = new TreeNode(parent);
            if (index.count(child) == 0) index[child] = new TreeNode(child);
            
            if (isLeft) index[parent]->left = index[child]; 
            else index[parent]->right = index[child];
        }
        for (auto child: childs) parents.erase(child);
        return index[*parents.begin()];
    }
};