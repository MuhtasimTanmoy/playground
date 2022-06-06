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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* itr = head;
        n++;
        while (n--) {
            if (!itr) return head ->next;
            itr = itr -> next;
        }
        ListNode* toRemove = head;
        
        while(itr) {
            itr = itr -> next;
            toRemove = toRemove -> next;
        }
        toRemove->next = toRemove->next->next;
        return head;
    }
};