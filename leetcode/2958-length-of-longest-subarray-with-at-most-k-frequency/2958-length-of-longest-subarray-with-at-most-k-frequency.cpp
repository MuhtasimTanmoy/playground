class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> counter;
        for (auto i = 0, l = 0; i < nums.size(); i++) {
            auto num = nums[i];
            counter[num]++;
            while (counter[num] > k) counter[nums[l++]]--;
            res = max(res, i - l + 1);
        }
        return res;
    }
};