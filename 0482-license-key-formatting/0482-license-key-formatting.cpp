class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int itr = 0;
        string res = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;
            if (itr != 0 && (itr % k == 0)) res += '-';
            itr++;
            res += toupper(s[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};