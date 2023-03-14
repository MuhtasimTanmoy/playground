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
        auto comp = [](const ListNode* a, const ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, 
                       vector<ListNode*>, 
                       decltype(comp)> frontier(comp);
        
        for (auto list: lists) if (list) frontier.push(list);
        auto head = new ListNode(), itr = head;
        while (frontier.size()) {
            auto top_node = frontier.top(); frontier.pop();
            itr = itr->next = new ListNode(top_node->val);
            if (top_node->next) frontier.push({top_node->next});
        }
        return head->next;
    }
};