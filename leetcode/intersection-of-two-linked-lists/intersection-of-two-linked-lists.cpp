/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto na = headA, nb = headB;
        
        while (na != nb) {
            // cout<<na->val<<"-"<<nb->val<<endl;
            na = na->next;
            nb = nb->next;
            if (na == nb) 
                break;
            
            if (!na) 
                na = headB;
            
            if (!nb) 
                nb = headA;
            
        }
        return na;
    }
};