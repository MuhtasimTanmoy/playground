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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto reverse = [](ListNode* l, int count, ListNode* prev = NULL) {
            while (l && count--) swap(l->next, prev), swap(l, prev);
            return prev;
        };
        
        auto pointer = new ListNode(-1, head);
        int count = 1;
        for (ListNode* itr = pointer, *holder = NULL; ; itr = itr->next, count++) {
            if (!itr || count == right + 1) {
                auto l = reverse(holder->next, right - left + 1, itr->next);
                holder->next = l;
                break;
            }
            if (count == left) holder = itr;
        }
        return pointer->next;
    }
};