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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> l, r;
        while (l1) l.push_back(l1->val), l1 = l1->next;
        while (l2) r.push_back(l2->val), l2 = l2->next;
        
        if (l.size() < r.size()) swap(l, r);
        int carry = 0;
        ListNode* res = NULL;
        while (l.size() || r.size()) {
            auto sum = (l.size() ? l.back(): 0) + (r.size() ? r.back(): 0) + carry;
            if (l.size()) l.pop_back();
            if (r.size()) r.pop_back();
            carry = sum > 9, sum = sum % 10;
            res = new ListNode(sum, res);
        }
        if (carry)  return new ListNode(1, res);
        return res;
    }
};