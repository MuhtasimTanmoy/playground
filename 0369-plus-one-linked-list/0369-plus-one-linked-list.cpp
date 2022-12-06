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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        while(curr) {
            swap(curr->next, prev);
            swap(curr, prev);
        }
        return prev;
    }
public:
    ListNode* plusOne(ListNode* head) {
        auto rev = reverseList(head);
        int rem = 0;
        bool first = true;
        ListNode* itr;
        for (itr = rev; itr; itr = itr->next) {
            if (first && ++itr->val == 10) {
                itr->val = 0;
                rem = 1;
            } else if (itr->val + rem == 10) {
                itr->val = 0;
                rem = 1;
            } else {
                itr->val += rem;
                rem = 0;
            }
            first = false;
        }
        auto rev2 = reverseList(rev);
        if (rem) return new ListNode(1, rev2);
        return rev2;
    }
};