class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> bag {'a', 'e', 'i', 'o', 'u'};
        int res = INT_MIN;
        for (int i = 0, l = 0, cnt = 0; i < s.size(); i++) {
            cnt += bag.count(s[i]);
            if (i == l + k) cnt -= bag.count(s[l++]);
            res = max(res, cnt);
        }
        return res;
    }
};