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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        auto has = unordered_set<int>(nums.begin(), nums.end());
        auto cache = new ListNode(0, head);
        for (auto now = head, prev = cache; now; now = now->next) {
            if (has.count(now->val))
                prev->next = now->next;
            else prev = now;
        }
        return cache->next;
    }
};