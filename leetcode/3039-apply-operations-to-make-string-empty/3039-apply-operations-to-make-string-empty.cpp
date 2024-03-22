class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> count(26, 0);
        for (auto c: s) count[c - 'a']++;
        auto max_count = *max_element(count.begin(), count.end());
        string res;
        for (int i = s.size() - 1; i >= 0; i--)
            if (count[s[i] - 'a'] == max_count) 
                res = s[i] + res,
                count[s[i] - 'a'] = 0;
        return res;
    }
};