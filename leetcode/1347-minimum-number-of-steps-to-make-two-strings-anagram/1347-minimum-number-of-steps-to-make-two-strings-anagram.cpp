class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++cnt1[s[i]-'a'];
            ++cnt2[t[i]-'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) 
            res += min(cnt1[i], cnt2[i]);
        
        return s.size() - res;
    }
};