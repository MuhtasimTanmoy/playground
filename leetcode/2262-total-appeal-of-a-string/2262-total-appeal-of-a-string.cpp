class Solution {
public:
    // https://leetcode.com/problems/total-appeal-of-a-string/discuss/1996390/
    long long appealSum(string s) {
        vector<int> last(26);
        long res = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i + 1;
            for (int j: last)
                res += j;
        }
        return res;
    }
};