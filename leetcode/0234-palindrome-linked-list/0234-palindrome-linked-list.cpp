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

/*
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
            while (left < right) 
                if (s[left++] != s[right--]) 
                    return false;
            return true;
        };
        
        return isPalindrome();
    }
};
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) { 
            slow = slow->next;
            fast = fast->next->next;
        }  
        
        ListNode* rev = nullptr;
        while (slow) {
            auto nextToGo = slow->next;
            slow->next = rev;
            rev = slow;
            slow = nextToGo;
        }
        
        slow = head;
        while (rev && slow) {
            if ( slow->val != rev->val) return false;
            rev = rev->next;
            slow = slow->next;
        }
        return true;
    }
};