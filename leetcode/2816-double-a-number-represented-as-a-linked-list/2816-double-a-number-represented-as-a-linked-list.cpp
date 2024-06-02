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
    ListNode* doubleIt(ListNode* head) {
        auto rev = [](ListNode* now) {
            ListNode *prev = NULL;
            while (now) swap(prev, now->next), swap(prev, now);
            return prev;
        };
        ListNode *now = rev(head), *ret = now, *prev = NULL; auto residue = 0;
        while (now) {
            auto val = now->val * 2 + residue;
            now->val = val % 10;
            residue = val > 9 ? 1 : 0;
            prev = now;
            now = now->next;
        }
        if (residue) prev->next = new ListNode(residue);
        return rev(ret);
    }
};