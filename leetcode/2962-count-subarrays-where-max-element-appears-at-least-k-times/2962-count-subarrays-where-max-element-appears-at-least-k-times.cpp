class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0, n = nums.size();
        auto max_elem = *max_element(nums.begin(), nums.end());
        for (auto l = 0, r = 0, max_elem_count = 0; r < n; r++) {
            max_elem_count += nums[r] == max_elem;
            while (max_elem_count == k) {
                max_elem_count -= nums[l++] == max_elem;
                res += n - r;
            }
        }
        return res;
    }
};