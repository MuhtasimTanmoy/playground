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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        function<int(int, int)> gcd = [&gcd](int a, int b) {
            if (b == 0) return a;
            if (a < b) swap(a, b);
            return gcd(b, a - b);
        };
                
        for (auto i = head; i->next != NULL; ) {
            auto one = i->val, two = i->next->val;
            auto ins = gcd(one, two);
            auto node = new ListNode(ins, i->next);
            
            auto cache = i->next;
            i->next = node;
            i = cache;
        }
        
        return head;
    }
};