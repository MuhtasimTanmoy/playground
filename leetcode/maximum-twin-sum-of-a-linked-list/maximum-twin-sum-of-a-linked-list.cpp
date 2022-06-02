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
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        stack<int> list;
        while(fast && fast->next) { 
            list.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        int result = INT_MIN;
        while (slow) {
            result = max(result, list.top() + slow->val);
            list.pop();
            slow = slow->next;
        }
        return result;
    }
};