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
    ListNode* sortList(ListNode* head) {
        
        vector<int> list;
        ListNode* itr = head;
        while(itr) {
            list.push_back(itr->val);
            itr = itr->next;
        }
        
        sort(list.begin(), list.end());
        itr = head;
        int index = 0;
        while(itr) {
            itr->val = list[index++];
            itr = itr->next;
        }
        
        return head;
    }
};