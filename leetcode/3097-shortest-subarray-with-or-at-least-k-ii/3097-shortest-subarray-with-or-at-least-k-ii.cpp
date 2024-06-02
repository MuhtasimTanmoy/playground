/*
// gets TLE

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // int n = nums.size(), min_length = INT_MAX;
        // for (int left = 0, right = 0, curr_or = 0; right < n; ++right) {
        //     curr_or |= nums[right];
        //     while (left <= right && curr_or >= k) 
        //         min_length = min(min_length, right - left + 1),
        //         curr_or &= ~nums[left],
        //         left++;
        // }
        // return min_length != INT_MAX ? min_length : -1;
        
        int ans = INT_MAX;
        for (auto i = 0; i < nums.size(); i++) {
             int res = 0;
             for (auto j = i; j < nums.size() && (j - i + 1) < ans; j++) {
                 res |= nums[j];
                 if (res >= k) {
                     ans = min(ans, j - i + 1);
                     break;
                 }
             }
        }
        return ans == INT_MAX ? -1: ans;
    }
};
*/

class Solution {
public:
//     int minimumSubarrayLength(vector<int>& nums, int k) {
//         int n = nums.size(), ans = INT_MAX;
//         vector<int> tracker(32, 0);
        
//         auto is_valid = [&]() {
//             for (auto i = 0; i < tracker.size(); i++) {
//                 auto k_set_bit = (k >> i) & 1;
//                 if (k_set_bit) if (!tracker[i]) return false;
//             }
//             return true;
//         };
        
//         auto process = [&](auto curr, auto to, bool set) {
//             for (auto i = 0; i < tracker.size(); i++) {
//                 auto to_set = (to >> i) & 1, k_set_bit = (k >> i) & 1;
//                 if (k_set_bit && to_set) {
//                     tracker[i] += set ? 1: -1;
//                 }
//             }
//             return curr | to;
//         };
            
//         for (auto l = 0, r = 0, curr_or = 0; r < n; ++r) {
//             curr_or = process(curr_or, nums[r], true);
//             while (l <= r && curr_or >= k) 
//                 ans = min(ans, r - l + 1),
//                 curr_or = process(curr_or, nums[l], false),
//                 l++;
//         }
//         return ans != INT_MAX ? ans : -1;
//     }
    
    void performOrOperation(vector<int>& bitCount, int& orVal, int n) {
        orVal = (orVal | n);
        for (int t = 0; t < 32; ++t) bitCount[t] += (n & (1 << t)) ? 1 : 0;
    }

    void nullifyOrOperation(vector<int>& bitCount, int& orVal, int n){
        for (int t = 0; t < 32; ++t) {
            bitCount[t] += (n & (1 << t)) ? -1 : 0;
            if (bitCount[t] == 0) orVal = orVal & (~(1<<t));
        }
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int orVal = 0, ans = INT_MAX;
        vector<int> bitCount(32, 0);
        for (int i = 0, j = 0; i < nums.size(); ++i){
            performOrOperation(bitCount, orVal, nums[i]);
            if (orVal < k) continue; 
            for ( ;j <= i && orVal >= k; j++)
                nullifyOrOperation(bitCount, orVal, nums[j]),
                ans = min(ans, i - j + 1);
        }
        return (ans == INT_MAX)? -1: ans;
    }
};

