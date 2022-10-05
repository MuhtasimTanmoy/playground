/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            auto item = node->right;
            while (item->left) item = item->left;
            return item;
        } 
        
        while (node) {
            auto parent = node->parent;
            if (parent) if (parent->left == node) return parent;
            node = parent;
        }
        return NULL;
    }
};