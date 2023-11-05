/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapper;
        
        Node* p = new Node(-1);
        for (auto now = head, prev = p; now; now = now->next) {
            auto proxy = new Node(now->val);
            prev->next = proxy;
            prev = proxy;
            mapper[now] = proxy;
        }
        
        for (auto now = head, para = p->next; now; 
             now = now->next, para = para->next) {
            if (now->random) para->random = mapper[now->random];
        }
        return p->next;
    }
};