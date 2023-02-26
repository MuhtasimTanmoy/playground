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
    ListNode* swapPairs(ListNode* head) {
        auto itr = new ListNode(-1, head);
        auto prev = itr;
        while (head && head->next) {
            auto first = head, second = head->next;
            
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            prev = first;
            head = first->next;
        }
        return itr->next;
    }
};