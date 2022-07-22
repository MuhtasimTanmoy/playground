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
    unordered_map<int, int> counter;
    int findFrequent(TreeNode* root) {
        auto left = root->left ? findFrequent(root->left) : 0;
        auto right = root->right ? findFrequent(root->right) : 0;
        auto sum = left + right + root->val;
        counter[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root) findFrequent(root);
        vector<int> res;
        int maxFreq = -1;
        for (auto [val, frequency]: counter) {
            if (frequency > maxFreq) {
                res.clear();
                res.push_back(val);
                maxFreq = frequency;
            } else if (frequency == maxFreq) res.push_back(val);
        }
        return res;
    }
};