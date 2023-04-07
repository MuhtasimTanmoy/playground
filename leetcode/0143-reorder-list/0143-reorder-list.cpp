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
    
    // void swap(ListNode* a, ListNode* b) {
    //     auto temp = a;
    //     a = b;
    //     b = temp;
    // }
    
    //         while (slow) {
    //             auto slow_next = slow->next;
    //             cout<<slow->val<<endl;
    //             slow = slow_next;
    //         }

    //          while (back) {
    //             auto slow_next = back->next;
    //             cout<<back->val<<endl;
    //             back = slow_next;
    //         }
    
    ListNode* reverse(ListNode* head) {
        ListNode* itr = head, *prev = NULL;
        while (itr) {
            swap(itr->next, prev);
            swap(prev, itr);
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) 
            slow = slow->next,
            fast = fast->next->next;
        
        auto back = reverse(slow->next);
        slow->next = NULL;
        slow = head;
        
        while (slow && back) {
            auto slow_next = slow->next, back_next = back->next;
            
            slow->next = back;
            back->next = slow_next;
            
            back = back_next;
            slow = slow_next;
        }
    }
};