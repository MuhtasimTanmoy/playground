/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
//     vector<int> res;
//     int traverseCount = -1;
//     bool startCount = false;
    
//     void traverse(TreeNode* root, TreeNode* target, int k) {
        
//         if (startCount) {
//             if (traverseCount >= 0) traverseCount++;
//             else traverseCount--;
//         }
        
//         if (abs(traverseCount) == k) res.push_back(root->val);
        
//         if (root == target) {
//             startCount = true;
//             traverseCount = 0;
//         }
        
//         if (root->left) {
//             traverse(root->left, target, k);
//             if (startCount) {
//                 if (traverseCount >= 0) traverseCount--;
//                 else traverseCount++;
//             }
//         }
        
//         if (root->right) {
//             traverse(root->right, target, k);
//             if (startCount) {
//                 if (traverseCount >= 0) traverseCount--;
//                 else traverseCount++;
//             }
//         }
//     }
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         if (root) traverse(root, target, k);
//         return res;
//     }
// };

class Solution {
    unordered_map<int,vector<int>> graph;
    
    void makeGraph(TreeNode* root, TreeNode* parent) {
        if (root == nullptr) return;
        
        if (parent != nullptr) {
            graph[root->val].push_back(parent->val);
            graph[parent->val].push_back(root->val);
        }
        
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
        
        while (!que.empty()) {
            
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