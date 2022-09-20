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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        ListNode* dummy = new ListNode(), * traverse = dummy;
        for (auto list: lists) if (list) q.push(list);
        while(q.size()) {
            auto item = q.top();
            q.pop();
            if (item->next) q.push(item->next);
            traverse->next = item;
            traverse = traverse->next;
        }
        return dummy->next;
    }
};