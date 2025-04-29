class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        unordered_set<int> blacklisted;
        for (auto h = head; h->next; h = h->next) 
            if (h->val == h->next->val) blacklisted.insert(h->val);
        
        auto track = new ListNode(-1, head), pre = track;
        for (auto h = head; h; h = h->next) 
            if (blacklisted.count(h->val)) pre->next = h->next;
            else pre = pre->next;
        
        return track->next;
    }
};