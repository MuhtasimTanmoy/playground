class Solution {
public:
    string removeVowels(string s) {
        unordered_set<char> bag {'a', 'e', 'i', 'o', 'u'};
        string res = "";
        for (auto c: s) if (!bag.count(c)) res += c;
        return res;
    }
};