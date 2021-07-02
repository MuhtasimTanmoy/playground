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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* result = new ListNode();
        ListNode* head = result;
        
        while(l1 || l2) {
                        
            result->next = new ListNode();
            result = result->next;
     
            int l1Value = l1 == nullptr ? INT_MAX : l1->val;
            int l2Value = l2 == nullptr ? INT_MAX : l2->val;
            
            if (l1Value < l2Value) {
               result->val = l1Value; 
               l1 = l1 -> next;
            } else {
                result->val = l2Value;
                l2 = l2 -> next;
            }
        }
        
        return head->next;
        
    }
};