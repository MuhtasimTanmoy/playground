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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        auto l = -1, r = -1, min_dist = INT_MAX, index = 0;
        for (auto now = head->next, prev = head; now->next; now = now->next) {
            auto is_greater = prev->val > now->val && now->next->val > now->val,
                 is_lesser = prev->val < now->val && now->next->val < now->val;
            if (is_greater || is_lesser) {
                if (l == -1) l = index;
                if (r != -1) min_dist = min(min_dist, index - r);
                r = index;
            }
            index++, prev = now;
        }
        if (r == l) return {-1, -1}; else return {min_dist, r - l};
    }
};