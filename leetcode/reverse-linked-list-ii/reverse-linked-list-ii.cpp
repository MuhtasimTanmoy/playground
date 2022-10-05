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
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         ListNode *leftP = head;
//         ListNode *rightP = head;
//         for(int i = 0; i < right; i++) {
//             if (i < left - 2) leftP = leftP->next;
//             rightP = rightP->next;
//         }
        
//         ListNode *itr = leftP -> next;
//         ListNode *prev = rightP;
        
//         int len = right - left + 1;
//         if (len == 1) return head;
        
//         while (len--) {
//             auto nextUp = itr->next;
            
//             itr->next = prev;
//             prev = itr;
            
//             itr = nextUp;
//         }
        
//         leftP->next = prev; 
//         return head;
//     }
// };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *dummy = new ListNode(-1, head), *cur = head, *pre = dummy;
        // dummy->next = head;
        int idx;
        for (idx = 1; idx < left; ++idx) {
            pre = cur;
            cur = cur->next;
        }
        auto now = cur;
        for (idx = left; idx <= right; ++idx) {
            now = now->next;
        }
        ListNode *revH = now;
        while (cur != now) {
            auto tmp = cur->next;
            cur->next = revH;
            revH = cur;
            cur = tmp;
        }
        pre->next = revH;
        return dummy->next;
    }
};