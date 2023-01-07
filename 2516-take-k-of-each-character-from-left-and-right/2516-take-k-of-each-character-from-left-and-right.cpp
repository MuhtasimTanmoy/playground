class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt[3] = {}, sz = s.size(), res = -1;
        for (auto ch : s)
            ++cnt[ch - 'a'];
        if (*min_element(begin(cnt), end(cnt)) < k)
            return -1;
        for (int i = 0, j = 0; i < sz; ++i) {
            if (--cnt[s[i] - 'a'] < k)
                while(cnt[s[i] - 'a'] < k)
                    ++cnt[s[j++] - 'a'];
            res = max(res, i - j + 1);
        }
        return sz - res;
    }
};