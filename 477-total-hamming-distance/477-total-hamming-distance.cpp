class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int ones = 0;
            for (auto &num: nums) {
                ones += ( num & 1);
                num >>= 1;
            }
            res += ones*(nums.size()-ones);
        }
        return res;
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