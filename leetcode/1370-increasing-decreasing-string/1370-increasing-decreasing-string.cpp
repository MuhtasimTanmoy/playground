class Solution {
public:
    string sortString(string s, string res = "") {
        vector<int> bag(26, 0);
        for (auto c: s) bag[c - 'a']++;
        while (s.size() != res.size()) {
            for (auto i = 0; i < 26; ++i)
                if (--bag[i] >= 0) res += 'a' + i;
            for (int i = 25; i >=0; --i)
                if (--bag[i] >= 0) res += 'a' + i;
        }
        return res;
    }
};