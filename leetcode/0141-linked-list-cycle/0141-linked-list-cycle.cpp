/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> dp;
        for (auto i = head; i; i = i->next) {
            if (dp.count(i)) return true;
            dp.insert(i);
        }
        return false;
    }
};