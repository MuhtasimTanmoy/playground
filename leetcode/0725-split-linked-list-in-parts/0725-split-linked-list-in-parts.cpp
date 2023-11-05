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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        for (auto now = head; now; now = now->next) len++;
        
        vector<ListNode*> res;
        auto run_length = len / k, extra = len > k ? len % k: 0;
                
        auto itr = head;
        while (itr) {
            auto curr = itr;
            for (int i = 0; i < run_length - 1 && curr; i++) curr = curr->next;
            if (extra && curr) curr = curr->next, extra--;
            
            res.push_back(itr);
            
            if (!curr) break;
            auto to = curr->next;
            curr->next = NULL;
            itr = to;
        }
        res.resize(k);
        return res;
    }
};