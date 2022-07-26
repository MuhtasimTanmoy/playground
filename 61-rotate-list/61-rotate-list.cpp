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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        if (!head->next) return head;
        if (k == 0) return head;
        
        ListNode *offset = head;
        
        int len = 1;
        while (offset->next && ++len) offset = offset->next;
        offset->next = head;
        k %= len;
        
        offset = head;
        for (int i = 0; i < len - k % len - 1; i++)
          offset = offset->next;
        auto res = offset->next;
        offset->next = NULL;
        return res;
    }
};