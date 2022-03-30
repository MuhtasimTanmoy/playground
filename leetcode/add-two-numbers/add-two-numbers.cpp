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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* addedNumberHead = new ListNode(0);
        ListNode* traverse = addedNumberHead;
        bool shouldAddOne = false;
        
        while( l1 != nullptr && l2 != nullptr) {
            
            int addResult = l1->val + l2->val;
            
            if (shouldAddOne) {
                addResult += 1;
                shouldAddOne = false;
            }
            
            if (addResult > 9) { 
                addResult = addResult - 10;
                shouldAddOne = true;
            }
            
            traverse->next =  new ListNode(addResult);
            l1 = l1 -> next;
            l2 = l2 -> next;
            traverse = traverse->next;
        }
        
        while( l1 != nullptr) {
            
            int addResult = l1->val;
            
            if (shouldAddOne) {
                addResult += 1;
                shouldAddOne = false;
            }
            if (addResult > 9) { 
                addResult = addResult - 10;
                shouldAddOne = true;
            }
            traverse->next =  new ListNode(addResult);
            l1 = l1 -> next;
            traverse = traverse->next;
        }
        
        while( l2 != nullptr) {
            
            int addResult = l2->val;
            
            if (shouldAddOne) {
                addResult += 1;
                shouldAddOne = false;
            }
            if (addResult > 9) { 
                addResult = addResult - 10;
                shouldAddOne = true;
            }
            traverse->next =  new ListNode(addResult);
            l2 = l2 -> next;
            traverse = traverse->next;
        }
        
        if (shouldAddOne) {
            traverse->next =  new ListNode(1);
        }
        return addedNumberHead->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *now = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            now->next = new ListNode(carry%10);
            now = now->next;
            carry /= 10;
        }
        return dummy->next;
    }
};