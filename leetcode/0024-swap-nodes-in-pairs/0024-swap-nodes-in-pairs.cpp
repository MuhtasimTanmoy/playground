class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        ListNode *itr = head, *prev = NULL, *ret = head->next;
        if (!ret) return head;
        
        while (itr && itr->next) {
            auto l = itr, r = l->next, cache = r->next;
            r->next = l;
            l->next = cache;
            itr = cache;
            
            if (prev) prev->next = r;
            prev = l;
        }
        return ret;
    }
};