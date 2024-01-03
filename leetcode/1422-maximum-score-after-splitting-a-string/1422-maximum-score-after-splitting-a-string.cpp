class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), res = 0;
        vector<int> zero_count(n);
        for (auto i = 0, zero = 0; i < n; i++) 
            zero += s[i] == '0',
            zero_count[i] = zero;
        for (auto i = 0; i < n - 1; i++) {
            auto right_one = (n - i - 1) - (zero_count.back() - zero_count[i]);
            res = max(res, zero_count[i] + right_one);
        }
        return res;
    }
};