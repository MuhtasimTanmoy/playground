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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *iter = head;
        ListNode *p1 = head; 
        ListNode *p2 = head;
        
        int count = 1;
        
        while(iter != NULL) {
            
            if ( count < k ) {
                p1 = p1->next;
            }
            
            if ( count > k ) {
                p2 = p2->next;
            }
            
            count++;
            iter = iter->next;
        }
        
        int temp = p1->val;
        p1->val = p2->val;
        p2->val = temp;
        
        return head;
    }
};