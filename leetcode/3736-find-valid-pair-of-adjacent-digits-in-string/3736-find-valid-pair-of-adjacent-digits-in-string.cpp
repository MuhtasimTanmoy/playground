class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> cnt;
        for (char c : s)  cnt[c]++;
        for (int i = 1; i < s.length(); ++i) 
            if (s[i] != s[i - 1] 
                && cnt[s[i]] == (s[i] - '0') 
                && cnt[s[i - 1]] == (s[i - 1] - '0')) return s.substr(i - 1, 2);
        return "";
    }
};