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
        stack<ListNode*> st1, st2;
        auto traverse1 = l1, traverse2 = l2;
        
        while (traverse1) st1.push(traverse1), traverse1 = traverse1->next;
        while (traverse2) st2.push(traverse2), traverse2 = traverse2->next;
        if (st1.size() < st2.size()) swap(l1, l2), swap(st1, st2);
        
        int carry = 0;
        while (st1.size()) {
            int add = carry;
            if (st2.size()) add += st2.top()->val;
            
            st1.top()->val += add;
            carry = st1.top()->val > 9;
            if (carry) st1.top()->val %= 10;
            
            st1.pop();
            if (st2.size()) st2.pop();
        }
        
        if (carry) return new ListNode(1, l1);
        return l1;
    }
};