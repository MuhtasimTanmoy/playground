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
    bool isPalindrome(ListNode* head) {
        string s = "";
        ListNode* itr = head;
        
        while(itr) {
            s += itr->val;
            itr = itr->next;
        }
        
        auto isPalindrome = [&]() -> bool {
            int left = 0, right = s.size() - 1;
            while (left < right) if (s[left++] != s[right--]) return false;
            return true;
        };
        
        return isPalindrome();
    }
};