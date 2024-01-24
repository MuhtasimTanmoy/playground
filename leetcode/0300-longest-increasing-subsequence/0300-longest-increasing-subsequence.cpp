// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         unordered_map<string, int> dp;
//         auto gen_key = [](int a, int b) {
//             return to_string(a) + "-" +  to_string(b);
//         };
//         function<int(int, int)> go = [&](auto i, auto prev) {
//             if (i == nums.size()) return 0;
//             auto key = gen_key(i, prev);
//             // if (dp.count(key)) return dp[key];
//             auto without = (prev >= nums[i]) ? go(i + 1, prev): 0,
//                  with = (prev < nums[i]) ? 1 + go(i + 1, nums[i]): go(i + 1, nums[i]);
//             return dp[key] = max(without, with);
//         };
//         return go(0, 0);
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
            if (it != sub.end()) *it = nums[i];
            else sub.push_back(nums[i]);
        }
        return sub.size();
    }
};