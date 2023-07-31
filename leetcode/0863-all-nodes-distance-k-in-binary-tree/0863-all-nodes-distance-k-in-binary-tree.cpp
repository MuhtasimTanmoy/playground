/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int,vector<int>> graph;
    void makeGraph(TreeNode* root, TreeNode* parent) {
        if (!root) return;
        
        if (parent != nullptr) 
            graph[root->val].push_back(parent->val),
            graph[parent->val].push_back(root->val);
        
        makeGraph(root->left, root);
        makeGraph(root->right, root);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        makeGraph(root, nullptr);
        
        vector<int> answer;
        unordered_set<int> visited;
        
        queue<pair<int,int>> que;
        que.push({target->val, 0});
        
        while (que.size()) {
            
            auto [node, distance] = que.front();
            que.pop();
        
            visited.insert(node);
            if (distance == k) {
                answer.push_back(node);
                continue;
            }
            
            for (auto next : graph[node])
                if (visited.find(next) == visited.end())
                    que.push({next, distance + 1});
        }
        return answer;
    }
};