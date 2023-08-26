class Solution {
public:
    long long appealSum(string s) {
        vector<int> last(26, 0);
        long long res = 0;
        for (int i = 0, curr = 0; i < s.size(); i++) {
            auto idx = s[i] - 'a';
            curr += i + 1 - last[idx];
            last[idx] = i + 1;
            res += curr;
        }
        return res;
    }
};