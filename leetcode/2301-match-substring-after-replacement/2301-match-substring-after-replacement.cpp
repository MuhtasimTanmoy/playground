class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& m) {
        unordered_map<char, unordered_set<char>> p;
        for (auto t: m) p[t[0]].insert(t[1]);
        for (int i = 0, j = 0; i + sub.size() <= s.size(); i++) {
            for (j = 0; j < sub.size(); j++)
                if (s[i + j] != sub[j] && p[sub[j]].count(s[i + j]) == 0)
                    break;
            if (j == sub.size()) return true;
        }
        return false;
    }
};