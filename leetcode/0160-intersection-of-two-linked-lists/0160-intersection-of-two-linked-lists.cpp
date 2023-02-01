/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto ta = headA, tb = headB;
        while ( ta != tb ) {
            ta = ta ? ta -> next: headB;
            tb = tb ? tb -> next: headA;
        }
        return ta;
    }
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *pA = headA;
//         ListNode *pB = headB;
//         while (pA != pB) {
//             pA = pA == nullptr ? headB : pA->next;
//             pB = pB == nullptr ? headA : pB->next;
//         }
//         return pA;
//     }
// };