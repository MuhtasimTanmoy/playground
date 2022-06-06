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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even = new ListNode(-1);
        ListNode* odd = new ListNode(-1);
        
        ListNode* evenItr = even;
        ListNode* oddItr = odd;
        
        ListNode* curr = head;
        while(curr) {
            oddItr->next = curr;
            oddItr = oddItr->next;
            curr = curr->next;
            
            if (!curr) break;
            
            evenItr->next = curr;
            evenItr = evenItr->next;
            curr = curr->next;
        }
        
        oddItr->next = even->next;
        evenItr->next = nullptr;
        return odd->next;
    }
};