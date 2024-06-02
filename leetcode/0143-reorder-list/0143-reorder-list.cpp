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
    void reorderList(ListNode* head) {
        
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) 
            slow = slow->next, fast = fast->next->next;
        
        auto reverse = [](ListNode* now) {
            ListNode* cache = NULL;
            while (now) swap(now->next, cache), swap(now, cache);
            return cache;
        };
        
        auto rev = reverse(slow->next);
        slow->next = NULL;
        slow = head;
        // while (rev) {
        //     cout<<rev->val<<endl;
        //     rev = rev->next;
        // }
        while (slow && rev) {
            cout<<slow->val<<" "<<rev->val<<endl;
            auto next_slow = slow->next, next_rev = rev->next;
            slow->next = rev;
            rev->next = next_slow;
            
            slow = next_slow;
            rev = next_rev;
        }
    }
};