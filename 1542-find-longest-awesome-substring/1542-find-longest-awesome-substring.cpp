// 146 / 153 Test case passed
// TLE
/*
class Solution {
public:
    int longestAwesome(string s) {
        
        auto isPowerOfTwo = [](int n) {
            return (n != 0) && ((n & (n - 1)) == 0);
        };
        
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int bit = 0;
            for (int j = i; j < s.size(); j++) {
                bit ^= (1 << (s[j] - '0'));
                
                auto isOdd = ((j - i) % 2 == 1);
                if ( isOdd ) {
                    if (bit == 0) ans = max(ans, j - i + 1);
                } else 
                    if (isPowerOfTwo(bit)) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    int longestAwesome(string s) {
        map<int, int> dp;
        int res = 0, mask = 0;
        dp[0] = -1;
        for (auto i = 0; i < s.size(); ++i) {
            mask ^= 1 << (s[i] - '0');
            if (dp.count(mask)) res = max(res, i - dp[mask]);
            for (auto j = 0; j <= 9; ++j) {
                auto newMask = mask ^ (1 << j);
                if (dp.count(newMask)) res = max(res, i - dp[newMask]);
            }
            if (!dp.count(mask)) dp[mask] = i;
        }
        return res;
    }
};