class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(26, 0);
        for (auto c: s) count[c - 'a']--;
        for (auto c: t) count[c - 'a']++;
        for (int i = 0; i < 26; i++) if (count[i] == 1) return 'a' + i;
        throw "error";
    }
};