class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* now = head, *cache = NULL;
        while (now) {
            swap(now->next, cache);
            swap(now, cache);
        }
        return cache;
    }
};