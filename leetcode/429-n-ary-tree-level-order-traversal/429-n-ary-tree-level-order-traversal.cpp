/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void traverse(Node* root, vector<vector<int>>& res) {
        queue<Node*> q;
        if(root) q.push(root);
        
        while(!q.empty()) {
            int qSize = size(q);
            vector<int> level;
            
            for(int i = 0; i < qSize; i++) {
                auto elem = q.front();
                level.push_back(elem->val);
                q.pop();
                
                for(auto child: elem->children) q.push(child);
            }
            res.push_back(level);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        traverse(root, result);
        return result;
    }
};