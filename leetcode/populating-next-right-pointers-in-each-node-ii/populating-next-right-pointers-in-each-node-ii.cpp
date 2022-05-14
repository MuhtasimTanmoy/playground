/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    
    Node* traverse(Node* root) {
        // the idea is to level order traversal in opposite order
        queue<Node*> q;
        if (root) q.push(root);
            
        while(!q.empty()) {
            
            Node* prev = nullptr;
            int sz = size(q);
            
            for(int i = 0; i < sz; i++) {
                
                auto curr = q.front();
                q.pop();

                curr->next = prev;
                prev = curr;
                
                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
            }
        }
        
        return root;
    }
    
public:
    Node* connect(Node* root) {
        return traverse(root);
    }
};