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
        queue<Node*> q;
        if (root) q.push(root);
        
        while(!q.empty()) {
            Node* next = NULL;
            auto qSize = size(q);
            
            for(int i = 0; i < qSize; i++) {
                auto item = q.front();
                q.pop();
                
                item->next = next;
                next = item;
                
                if(item->right) q.push(item->right);
                if(item->left) q.push(item->left);
            }
        }
        return root;
    }
public:
    Node* connect(Node* root) {
        return traverse(root);
    }
};