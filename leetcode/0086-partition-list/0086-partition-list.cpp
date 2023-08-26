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

// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         auto res = new ListNode();
//         auto itr = head, cache = res;
//         while (itr) {
//             if (itr->val < x) 
//                 res->next = new ListNode(itr->val),
//                 res = res->next;
//             itr = itr->next;
//         }
//         itr = head;
//         while (itr) {
//             if (itr->val >= x) 
//                 res->next = new ListNode(itr->val),
//                 res = res->next;
//             itr = itr->next;
//         }
//         return cache->next;
//     }
// };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto less = new ListNode(-1, NULL), itr_less = less;
        auto more = new ListNode(-1, NULL), itr_more = more;
        
        auto curr = head;
        while (curr) {
            if (curr->val < x) 
                itr_less->next = curr,
                itr_less = itr_less->next;
            else 
                itr_more->next = curr,
                itr_more = itr_more->next;
            curr = curr->next;
        }
        itr_more->next = NULL;
        itr_less->next = more->next;
        return less->next;
    }
};