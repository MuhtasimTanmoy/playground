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
    ListNode* removeNodes(ListNode* head) {
        ListNode tmp(INT_MAX);
        vector<ListNode*> st{ &tmp };
        for (auto p = head; p != nullptr; p = p->next) {
            while (st.back()->val < p->val) 
                st.pop_back();
            st.back()->next = p;
            st.push_back(p);
        }
        return tmp.next;
    }
};