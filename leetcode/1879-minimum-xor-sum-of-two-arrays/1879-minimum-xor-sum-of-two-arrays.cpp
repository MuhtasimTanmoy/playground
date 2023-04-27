class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        auto gen_key = [](auto l, auto ... r) {
            return (to_string(l) + ... + (to_string(r)));
        };
        unordered_map<string, int> cache;
        auto len = nums1.size();
        
        function<int(int, int)> go = [&](auto idx, auto mask) {
            if (idx == len) return 0;
            
            auto key = gen_key(idx, mask);
            if (cache.count(key)) return cache[key];
            
            int res = INT_MAX;
            for (auto i = 0; i < len; i++) {
                if (mask & (1 << i)) continue;
                auto calc = nums2[i] ^ nums1[idx];
                auto new_mask = mask | (1 << i);
                res = min(res, calc + go(idx + 1, new_mask));
            }
            return cache[key] = res;
        };
        
        return go(0, 0);
    }
    
//     int dp[15][17000];
//     int helper(vector<int> &nums1, vector<int>&nums2, int i, int mask) {
        
//         if (i >= nums1.size()) return 0;
//         if(dp[i][mask] != -1) return dp[i][mask];
        
//         int ans = INT_MAX;
//         for(int j = 0; j < nums2.size(); j++) {
//             if (mask&(1 << j)) continue;
    
//             int val = nums1[i]^nums2[j];
//             ans = min(ans, helper(nums1, nums2, i+1, mask|(1 << j)) + val);
//         }
//         return dp[i][mask] = ans;
//     }
    
//     int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
//         memset(dp, -1, sizeof(dp));
//         return helper(nums1, nums2, 0, 0);
//     }
};