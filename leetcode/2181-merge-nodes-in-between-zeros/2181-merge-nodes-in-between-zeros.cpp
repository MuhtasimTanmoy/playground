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
    ListNode* mergeNodes(ListNode* h) {
        ListNode *stay = NULL, *prev = NULL;
        for (ListNode* t = h; t; t = t->next)
            if (t->val == 0) 
                if (stay) prev = stay, stay = stay->next, stay->val = 0;
                else stay = t;
            else stay->val += t->val;
        if (prev) prev->next = NULL;
        return h;
    }
};