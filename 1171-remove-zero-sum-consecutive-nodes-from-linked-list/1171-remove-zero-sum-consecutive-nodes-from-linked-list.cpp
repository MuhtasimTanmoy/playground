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
    ListNode* removeZeroSumSublists(ListNode* head, int sum = 0) {
        unordered_map<int, ListNode*> sumToNode;
        auto proxy = new ListNode(); proxy->next = head;
        sumToNode[0] = proxy;
        for (auto traverse = head; traverse; traverse = traverse->next) {
            sum += traverse->val;
            
            if (sumToNode.count(sum)) {
                auto prevNode = sumToNode[sum];
                
                int localSum = sum;
                for (auto i = prevNode->next; i !=  traverse->next; i = i->next) {
                    localSum += i->val;
                    sumToNode.erase(localSum);
                }
                
                prevNode->next = traverse->next;
                sumToNode[sum] = prevNode;
            } else sumToNode[sum] = traverse;
        }
        return proxy->next;
    }
};