/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* cache = NULL, *first = NULL;
        function<void(Node*)> go = [&](Node* n) {
            if (!n) return;
            if (n->left) go(n->left);
            
            n->left = cache;
            if (cache) cache->right = n; else first = n;
            cache = n;
            
            if (n->right) go(n->right);
        };
        
        go(root);
        
        if (cache) cache->right = first;
        if (first) first->left = cache;
        return first; 
    }
};