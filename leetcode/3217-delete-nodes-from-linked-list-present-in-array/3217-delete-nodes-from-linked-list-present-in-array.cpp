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
        unordered_set<int> bag(nums.begin(), nums.end());
        ListNode *n = new ListNode(), *traverse = n;
        for (auto now = head; now; now = now->next) {
            if (bag.count(now->val)) continue;
            traverse->next = now;
            traverse = traverse->next;
        }
        traverse->next = NULL;
        return n->next;
    }
};