class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = 0, n = nums.size();
        vector<int> cnt(32, 0);
        for (auto num : nums) {
            int i = 0;
            while (num > 0) {
                cnt[i] += (num & 0x1);
                num >>= 1;
                i++;
            }
        }
        for (auto&& k : cnt) ans += k * (n - k);
        return ans;
    }
};

// int totalHammingDistance(vector<int>& nums) {
//     int ans = 0;
//     if (nums.empty()) return ans;
//     for (int i = 0; i < nums.size() - 1; i++)
//         for (int j = i + 1; j < nums.size(); j++)
//             ans += __builtin_popcount(nums[i] ^ nums[j]);
//     return ans;
// }