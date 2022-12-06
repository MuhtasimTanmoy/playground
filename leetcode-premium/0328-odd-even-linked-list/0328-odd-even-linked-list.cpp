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

// Got solution for odd even value
/*
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = head, *even = head;
        int oddIndex = 0, evenIndex = 0;
        while (odd && even) {
            while (even && (even->val % 2 == 1)) {
                even = even->next;
                evenIndex++;
            }
            while (odd && (odd->val % 2 == 0)) {
                odd = odd->next;
                oddIndex++;
            }
            if (!(odd && even)) break;
            if (oddIndex > evenIndex) {
                swap(even->val, odd->val);
                even = even->next; evenIndex++;
            }
            odd = odd->next; oddIndex++;
        }
        return head;
    }
};
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode *oddItr = head->next, *evenItr = head;
        ListNode *odd = oddItr, *even = evenItr;
        bool isEven = true;
        ListNode *itr = odd;
        while (itr && itr->next) {
            auto next = itr->next;
            if (isEven) {
                even->next = next;
                even = next;
            } else {
                odd->next = next;
                odd = next;
            }
            isEven = !isEven;
            itr = next;
        }
        if (odd) odd->next = NULL;
        even->next = oddItr;
        return evenItr;
    }
};
