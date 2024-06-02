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
    ListNode* mergeInBetween(ListNode* l, int a, int b, ListNode* r) {
        int idx = 0;
        ListNode *ra, *rb;
        for (auto now = l; now; now = now->next) {
            idx++;
            if (idx == a) ra = now;
            if (idx == b + 2) rb = now;
        }
        ra->next = r;
        while (r->next) r = r->next;
        r->next = rb;
        return l;
    }
};