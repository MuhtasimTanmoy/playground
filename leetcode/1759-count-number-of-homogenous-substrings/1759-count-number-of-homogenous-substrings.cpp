class Solution {
    const int MOD = 1e9 + 7;
public:
    int countHomogenous(string s) {
        auto count = 0;
        char prev = ' '; 
        for (auto i = 0, local = 0; i < s.size(); i++) {
            local = s[i] == prev ? local + 1: 1;
            count = (count + local) % MOD;
            prev = s[i];
        }
        return count;
    }
};