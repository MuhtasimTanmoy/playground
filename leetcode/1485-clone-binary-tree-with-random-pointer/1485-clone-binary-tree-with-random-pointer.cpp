/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    unordered_map<Node*, NodeCopy*> mmap;
public:
    NodeCopy* help(Node* root) {
        if (!root) return NULL;
        if (mmap.count(root)) return mmap[root];
        
        NodeCopy* newroot = new NodeCopy(root->val);
        mmap[root] = newroot;
        
        newroot->left = help(root->left);
        newroot->right = help(root->right);
        newroot->random = help(root->random);
        return newroot;
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        return help(root);
    }
};