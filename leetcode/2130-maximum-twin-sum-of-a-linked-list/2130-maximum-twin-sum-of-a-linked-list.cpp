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
    int pairSum(ListNode* head, int res = 0) {
        // get mid point
        auto slow = head, fast = head;
        while (fast && fast->next) 
            slow = slow->next, fast = fast->next->next;
        
        // reverse the later half
        fast = NULL;
        while (slow) swap(slow->next, fast), swap(fast, slow);
        
        // traverse from start and from mid to calculate sum
        for (slow = head; slow && fast; fast = fast->next, slow = slow->next)
            res = max(res, slow->val + fast->val);

        return res;
    }
};