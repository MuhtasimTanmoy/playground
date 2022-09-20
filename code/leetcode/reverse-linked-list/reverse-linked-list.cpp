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
    ListNode* reverseList(ListNode* head) {
        ListNode* rev = nullptr;
        while (head) {
            auto nextUp = head -> next;
            head->next = rev;
            rev = head;
            head = nextUp;
        }
        return rev;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *revH = nullptr, *cur = head;
//         while (cur) {
//             auto tmp = cur->next;
//             cur->next = revH;
//             revH = cur;
//             cur = tmp;
//         }
//         return revH;
//     }
// };