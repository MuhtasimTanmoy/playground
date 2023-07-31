// class Solution {
// public:
//     int countBeautifulPairs(vector<int>& nums) {
//         int cnt[10] = {}, res = 0;
//         for(int i = 0; i < nums.size(); ++i) {
//             for (int n = 1; n < 10; ++n)
//                 if (gcd(n, nums[i] % 10) == 1)
//                     res += cnt[n];
//             while (nums[i] >= 10)
//                 nums[i] /= 10;
//             ++cnt[nums[i]];
//         }
//         return res;
//     }
// };

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0,n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            string s = to_string(nums[i]);
            for (int j = i + 1; j < n; j++)
                if (__gcd(s[0] - '0', nums[j] % 10) == 1)
                    res++;
        }    
        return res;
    }
};