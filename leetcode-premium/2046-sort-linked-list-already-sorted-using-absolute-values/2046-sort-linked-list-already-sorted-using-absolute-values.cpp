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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* prev = NULL, *ans = head;
        for (auto itr = head; itr; itr = itr->next) {
            if (prev && itr->val < 0) {
                prev->next = itr->next;
                itr->next = ans;
                ans = itr;
                itr = prev;
            }
            prev = itr;
        }
        return ans;
    }
    // ListNode* sortLinkedList(ListNode* head) {
    //     for (ListNode * p = head, 
    //          *pp = nullptr; 
    //          p != nullptr; 
    //          p = p->next) {
    //             if (p->val < 0 && pp != nullptr) {
    //                 pp->next = p->next;
    //                 p->next = head;
    //                 head = p;
    //                 p = pp;
    //             }
    //             pp = p;
    //     }
    //     return head;
    // }
};