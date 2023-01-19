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
    ListNode* swapPairs(ListNode* head) {
        auto res = new ListNode(0, head);
        auto traverse = head;
        ListNode* prev = res;
        while (traverse && traverse->next) {
            prev->next = traverse->next;
            auto sec = traverse->next->next;
            traverse->next->next = traverse;
            traverse->next = sec;
            prev = traverse;
            traverse = sec;
        }
        return res->next;
    }
};