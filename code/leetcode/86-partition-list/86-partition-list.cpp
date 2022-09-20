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
    // ListNode* partition(ListNode* head, int x) {
    //     ListNode *dummy = new ListNode(-1, head);
    //     ListNode *traverse = dummy->next, *left = dummy, *prev = dummy;
    //     while (traverse) {
    //         auto cacheNext = traverse->next;
    //         cout<<traverse->val<<endl;
    //         if (traverse->val < x) {
    //             prev->next = prev->next->next;
    //             // insert in left
    //             traverse->next = left->next;
    //             left->next = traverse;
    //             // 
    //             left = left->next;
    //         } else prev = traverse;
    //         traverse = cacheNext;
    //         cout<<"Help"<<endl;
    //     }
    //     return dummy->next;
    // }
    
     ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(-1), *c1 = dummy1;
        ListNode *dummy2 = new ListNode(-1), *c2 = dummy2;
        ListNode *cur = head;
         
        while (cur) {
            if (cur->val < x) {
                c1->next = cur;
                c1 = c1->next;
            } else {
                c2->next = cur;
                c2 = c2->next;
            }
            cur = cur->next;
        }
        c2->next = NULL;
        c1->next = dummy2->next;
        return dummy1->next;
    }
};