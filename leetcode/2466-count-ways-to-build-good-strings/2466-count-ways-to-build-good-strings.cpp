/* Gets TLE
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        unordered_set<string> cache;
        int res = 0;
        function<void(string)> go = [&](auto term) {
            if (term.size() > high) return;
            if (term.size() >= low && term.size() <= high) {
                if (cache.count(term)) return;
                cache.insert(term);
                res++;
            }
            go(term + string(zero, '0'));
            go(term + string(one, '1'));
        };
        go("");
        return res;
    }
};
*/

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        
        int res = 0, mod = 1e9 + 7;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % mod;
            if (i >= low) res = (res + dp[i]) % mod;
        }
        return res;
    }
};