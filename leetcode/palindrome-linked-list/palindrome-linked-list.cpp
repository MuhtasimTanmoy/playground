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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next) { 
            slow = slow->next;
            fast = fast->next->next;
        }        
        
        ListNode* rev = nullptr;
        while(slow) {
            auto cache = slow->next;
            slow->next = rev;
            rev = slow;
            slow = cache;
        }
        
        slow = head;
        while (rev && slow) {
            if ( slow->val != rev->val) return false;
            rev = rev->next;
            slow = slow->next;
        }
        return true;
    }
};
