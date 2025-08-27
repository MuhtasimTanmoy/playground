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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* curr = p;
        unordered_set<int> bag;
        while(curr) {
            bag.insert(curr->val);
            curr = curr->parent;
        }
        curr = q;
        while(curr) {
            if (bag.count(curr->val)) return curr;
            curr = curr->parent;
        }
        return NULL;
    }
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *nodep = p, *nodeq = q;
        while (nodep != nodeq) {
            nodep = nodep->parent;
            nodeq = nodeq->parent;
            if (nodep == nodeq) return nodep;
            if (!nodep) nodep = q;
            if (!nodeq) nodeq = p;
        }
        return nodep;
    }
};