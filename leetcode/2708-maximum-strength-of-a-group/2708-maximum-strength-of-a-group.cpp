// class Solution {
// public:
//     long long maxStrength(vector<int>& nums) {
//         long long multi = 1; int max_neg = INT_MIN, zero = 0;
//         for (auto num: nums) {
//             if (num) multi *= num; else zero++;
//             if (num < 0) max_neg = max(max_neg, num);
//         }
//         if (nums.size() == 2 && zero && max_neg != INT_MIN) return 0;
//         if (max_neg == INT_MIN) return multi;
//         if (multi < 0) return multi / max_neg;
//         return multi;
//     }
// };

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long maxi = INT_MIN;
        for (int i = 1; i < (1 << n); i++) {
            long long cur = 1;
            for (int p = 0; p < n; p++) 
                if (i & (1 << p)) 
                    cur = (cur * nums[p]);
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};