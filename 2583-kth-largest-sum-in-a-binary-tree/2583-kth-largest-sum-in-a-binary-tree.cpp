/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        priority_queue<long long> pq;
        vector<TreeNode*> q;
        q.push_back(root);
        
        while (q.size()) {
            auto sz = q.size();
            long long sum = 0;
            
            vector<TreeNode*> temp;
            while (sz--) {
                auto elem = q.back(); q.pop_back();
                sum += elem->val;
                if (elem->left) temp.push_back(elem->left);
                if (elem->right) temp.push_back(elem->right);
            }
            pq.push(-sum);
            if (pq.size() == k + 1) pq.pop();
            swap(temp, q);
        }
        
        if (pq.size() != k) return -1;
        while (pq.size() != k) pq.pop();
        return -pq.top();
    }
};