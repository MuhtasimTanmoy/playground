/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // Node* flatten(Node* head) {
    //     function<Node*(Node*)> go = [&go](auto now) {            
    //         while (now->next) {
    //             auto next = now->next;
    //             if (now->child) {
    //                 now->next = now->child;
    //                 now->child->prev = now;
    //                 now->child->next = next;
    //                 next->prev = go(now->child);
    //                 now->child = NULL;
    //             }
    //             now = next;
    //         }
    //         return now;
    //     };
    //     go(head);
    //     return head;
    // }
    Node* flatten(Node* head, Node* rest = nullptr) {
      if (!head) return rest;
      head->next = flatten(head->child, flatten(head->next, rest));
      if (head->next) head->next->prev = head;
      head->child = nullptr;
      return head;
    }
};