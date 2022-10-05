/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* iterator = head;
        
        if (iterator == nullptr) { return head; }
        
        while(iterator->next != nullptr) {
            if (iterator -> val == iterator -> next -> val) {
                iterator->next = iterator -> next -> next;
            } else {
                iterator = iterator -> next;
            }
        }
        
        return head;
    }
};