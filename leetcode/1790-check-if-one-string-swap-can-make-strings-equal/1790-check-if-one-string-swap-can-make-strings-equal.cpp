class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diffIndex;
        for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) diffIndex.push_back(i);
        if (!diffIndex.size()) return true;
        if (diffIndex.size() != 2) return false;
        auto one = diffIndex[0], two = diffIndex[1];
        return s1[one] == s2[two] && s1[two] == s2[one];
    }
};