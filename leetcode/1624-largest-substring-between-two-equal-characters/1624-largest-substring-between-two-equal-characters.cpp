class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, int> first;
        for (auto i = 0; i < s.size(); i++) if (!first.count(s[i])) first[s[i]] = i;
        int res = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (!first.count(s[i])) continue;
            res = max(res, i - first[s[i]] - 1);
        }
        return res;
    }
};