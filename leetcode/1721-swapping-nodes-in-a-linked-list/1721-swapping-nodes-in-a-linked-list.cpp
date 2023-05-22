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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *l = head, *r = head, *itr = head;
        while (--k) l = l->next; itr = l;
        while (itr->next) 
            itr = itr->next, r = r->next;
        swap(l->val, r->val);
        return head;
    }
};