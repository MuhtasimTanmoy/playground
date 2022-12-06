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
    // ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    //     unordered_map<int, int> counter;
    //     ListNode* itr = head;
    //     while (itr) {
    //         counter[itr->val]++;
    //         itr = itr->next;
    //     }
    //     ListNode* res, *ret;
    //     itr = head;
    //     while (itr) {
    //         if (counter[itr->val] == 1) {
    //             if (!res) {
    //                 res = itr;
    //                 ret = itr;
    //             } else {
    //                 res->next = itr;
    //                 res = itr;
    //             }
    //         }
    //         itr = itr->next;
    //     }
    //     itr->next = NULL;
    //     return ret;
    // }
    
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode tmp(0, head);
        unordered_map<int, int> m;
        for (auto p = head; p != nullptr; p = p->next)
            ++m[p->val];
        
        for (auto p = &tmp, 
             c = &tmp; p != nullptr; 
             p = p->next) {
            
            c->next = p->next;
            if (p->next && m[p->next->val] == 1)
                c = c->next;
        }
        return tmp.next;
    }
};