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
    ListNode* doubleIt(ListNode* head) {
        auto reverse = [](ListNode* head) {
            ListNode* now = head, *prev = NULL;
            while (now) 
                swap(now->next, prev),
                swap(now, prev);
            return prev;
        };
        
        head = reverse(head);
        
        int residue = 0;
        for (ListNode* it = head, *prev = NULL; it || residue; it = it->next) {
            if (!it) {
                prev->next = new ListNode(residue, NULL);
                break;
            }
            
            auto val = it->val * 2 + residue;
            it->val = val % 10;
            residue = val / 10;
            
            prev = it;
        }
        return reverse(head);
    }
};