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
        vector<int> res;
        auto itr = head;
        while (itr) {
            res.push_back(itr->val);
            itr = itr->next;
        }
        
        vector<int> suff;
        for (int i = res.size() - 1; i >= 0; i--)
            if (suff.empty()) {
                suff.push_back(res[i]);
                res[i] = 0;
            } else {
                while (suff.size() && suff.back() <= res[i]) suff.pop_back();
                auto cache = res[i];
                res[i] = suff.size() ? suff.back() : 0;
                suff.push_back(cache);
            }
        return res;
    }
};