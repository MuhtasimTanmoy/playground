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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto itr = head;
        ListNode* l = new ListNode(0, head);
        
        auto forward = n;
        while (itr && forward--) itr = itr->next;
        if (!itr) return head->next;
        
        while (itr) l = l->next, itr = itr->next;
        if (l->next) l->next = l->next->next;
        return head;
    }
};