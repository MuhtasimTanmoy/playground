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
        ListNode *dummy = new ListNode(-1, head), *leftP = head, *pre = dummy;
        for (int idx = 1; idx < left; ++idx) {
            pre = leftP;
            leftP = leftP->next;
        }
        auto rightP = leftP;
        for (int idx = left; idx <= right; ++idx) rightP = rightP->next;
        
        ListNode *revH = rightP;
        while (leftP != rightP) {
            auto tmp = leftP->next;
            leftP->next = revH;
            revH = leftP;
            leftP = tmp;
        }
        pre->next = revH;
        return dummy->next;
    }
};