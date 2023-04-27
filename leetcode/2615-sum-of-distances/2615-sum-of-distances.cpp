class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> res(nums.size(), 0);
        unordered_map<int, long long> l_sum, l_cnt, r_sum, r_cnt;
        for (int i = 0; i < nums.size(); i++) {
            auto elem = nums[i];
            res[i] = l_cnt[elem] * i - l_sum[elem],
            l_sum[elem] += i,
            l_cnt[elem]++;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            auto elem = nums[i];
            res[i] +=  r_sum[elem] - r_cnt[elem] * i,
            r_sum[elem] += i,
            r_cnt[elem]++;
        }
        return res;
    }
};