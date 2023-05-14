class Solution {
public:
    long long appealSum(string s) {
        long long res = 0, cur = 0, prev[26] = {};
        for (int i = 0; i < s.size(); ++i) 
            cur += i + 1 - prev[s[i] - 'a'],
            prev[s[i] - 'a'] = i + 1,
            res += cur;
        return res;
    }
};