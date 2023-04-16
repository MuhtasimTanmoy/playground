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
    unordered_map<Node*, Node*> um;
public:
    Node* cloneTree(Node* root) {
        if (!root) return NULL;
        if (um.count(root)) return um[root];
        
        auto n = new Node(root->val);
        vector<Node*> children;
        for (auto child: root->children) children.push_back(cloneTree(child));
        n->children = children;
        return n;
    }
};