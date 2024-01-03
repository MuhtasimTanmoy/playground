class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for (auto c: s) cnt[c - 'a']++;
        for (auto c: t) cnt[c - 'a']--;
        for (auto i: cnt) if (i) return false;
        return true;
    }
};