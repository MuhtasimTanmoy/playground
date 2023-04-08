class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size(), -1), stk;
        for (int i = 0; i < 2 * n; i++) {
            while (stk.size() && nums[stk.back()] < nums[i % n]) {
                auto elem = stk.back(); stk.pop_back();
                res[elem] = nums[i % n];
            }
            stk.push_back(i%n);
        }
        return res;
    }
};