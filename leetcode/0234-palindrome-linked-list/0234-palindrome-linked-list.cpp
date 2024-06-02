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

// Intuition
// 1. Convert this into a vector and check
// 2. Traverse and reverse half of nodes
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        auto reverse = [](ListNode* head) {
            ListNode* now = head, *cache = NULL;
            while (now) swap(now->next, cache), swap(now, cache);
            return cache;
        };
        
        ListNode *now = head, *fast = head;
        while (fast && fast->next) 
            now = now->next, fast = fast->next->next;
        
        auto second = reverse(now);
        now = head;
        
        while (now && second) {
            if (now->val != second->val) return false;
            now = now->next;
            second = second->next;
        }
        return true;
    }
};