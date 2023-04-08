/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> v;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        auto curr = new Node(node->val);
        v[node->val] = curr;
        
        vector<Node*> neighbors;
        for (auto c: node->neighbors) 
            neighbors.push_back(v.count(c->val) ? v[c->val]: cloneGraph(c));
        curr->neighbors = neighbors;
        return curr;
    }
};