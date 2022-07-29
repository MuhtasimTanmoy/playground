class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> bag;
        for (auto num: nums1) bag.insert(num);
        stack<int> stk;
        unordered_map<int, int> mapping;
        for (int i = size(nums2) - 1; i >= 0; i--) {
            auto curr = nums2[i];
            while(!stk.empty() && stk.top() < curr) stk.pop();
            if (bag.count(curr)) mapping[curr] = stk.empty() ? -1: stk.top();
            stk.push(curr);
        }
        vector<int> res;
        for (auto n: nums1) res.push_back(mapping[n]);
        return res;
    }
};