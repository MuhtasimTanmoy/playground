/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *pre, *cur = node;
        while (cur->next) {
            cur->val = cur->next->val;
            pre = cur;
            cur = cur->next;
        }
        pre->next = nullptr;
    }
};