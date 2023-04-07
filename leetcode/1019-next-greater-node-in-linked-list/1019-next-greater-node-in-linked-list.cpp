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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> p;
        for (auto itr = head; itr; itr = itr->next) p.push_back(itr->val);
        vector<int> res(p.size()), stk;
        for (auto i = 0; i < p.size(); i++) {
            while (stk.size() && p[i] > p[stk.back()]) {
                auto index = stk.back();
                res[index] = p[i];
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return res;
    }
};