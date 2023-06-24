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
    ListNode* reverse(ListNode* itr) {
        ListNode* n = itr, *now = NULL;
        while (n) 
            swap(now, n->next),
            swap(n, now);
        return now;
    }
public:
    void reorderList(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) 
            slow = slow->next,
            fast = fast->next->next;
        
        auto r = reverse(slow->next);
        slow->next = NULL;
        slow = head;
        
        while (r && slow) {
            auto next = slow->next, r_next = r->next;
            
            slow->next = r;
            r->next = next;
            
            slow = next;
            r = r_next;
        }
    }
};