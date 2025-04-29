class Solution {
public:
    string longestCommonPrefix(vector<string>& S) {
        string common;
        for (auto i = 0, can = 1; i < S.front().size() && can; i++) {
            auto c = S.front()[i];
            for (auto s: S) 
                if (i == s.size() || s[i] != c) { can = 0; break; }
            if (can) common += c;
        }
        return common;
    }
};