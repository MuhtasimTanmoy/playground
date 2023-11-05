class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0); vector<bool> seen(26, false);
        for (auto c: s) cnt[c - 'a']++;
        string res = "";
        for (auto c: s) {
            cnt[c - 'a']--;
            if (seen[c - 'a']) continue;
            while (res.size() && res.back() > c && cnt[res.back() - 'a'] > 0)
                seen[res.back() - 'a'] = false,
                res.pop_back();
            seen[c - 'a'] = true;
            res.push_back(c);
        }
        return res;
    }
};

