/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
    // ListNode *detectCycle(ListNode *head) {
    //     unordered_set<ListNode*> cache;
    //     ListNode* itr = head;
    //     while (itr && itr->next) {
    //         if (cache.count(itr)) return itr;
    //         cache.insert(itr);
    //         itr = itr->next;
    //     }
    //     return NULL;
    // }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!(fast && fast->next)) return NULL;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};