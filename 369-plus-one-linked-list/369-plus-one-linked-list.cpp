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
//     ListNode* plusOne(ListNode* head) {
//         // sentinel head
//         ListNode* sentinel = new ListNode(0);
//         sentinel->next = head;
//         ListNode* notNine = sentinel;

//         // find the rightmost not-nine digit
//         while (head != nullptr) {
//             if (head->val != 9) notNine = head;
//             head = head->next;
//         }
//         // increase this rightmost not-nine digit by 1
//         notNine->val++;
//         notNine = notNine->next;
//         // set all the following nines to zeros
//         while (notNine != nullptr) {
//             notNine->val = 0;
//             notNine = notNine->next;
//         }

//         delete notNine;
//         return sentinel->val != 0 ? sentinel : sentinel->next;
//     }
// };

class Solution {
    void traverse(ListNode* head, int& rem) {
        if (!head) {
            rem = 1;
            return;
        }
        traverse(head->next, rem);
        if (rem) {
            head->val++;
            if (head->val > 9) head->val = 0;
            else rem = 0;
        }
    }
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* sentinel = new ListNode(1);
        int rem = 0;
        traverse(head, rem);
        if (rem) {
            sentinel->next = head;
            return sentinel;
        } else
            return head;
    }
};