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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* itr1 = list1;
        ListNode* itr2 = list2;
        
        ListNode* result = new ListNode();
        ListNode* r = result;

        while(itr1 && itr2) {
            if (itr1->val < itr2->val) {
                result->next = itr1;
                itr1 = itr1->next;
            } else {
                result->next = itr2;
                itr2 = itr2->next;
            }
            result = result->next;
        }
        
        while(itr1) { result->next = itr1; 
                     itr1 = itr1->next; 
                     result = result->next; }
        
        while(itr2) { result->next = itr2;
                     itr2 = itr2->next;
                     result = result->next; }
        
        return r->next;
    }
};