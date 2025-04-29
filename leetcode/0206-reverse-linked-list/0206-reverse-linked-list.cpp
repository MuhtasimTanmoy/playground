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
    ListNode* reverseList(ListNode* n) {
        auto rev = [](ListNode* n) {
            ListNode* prev = NULL;
            while (n) 
                swap(prev, n->next),
                swap(n, prev);
            return prev;
        };
        return rev(n);
    }
};