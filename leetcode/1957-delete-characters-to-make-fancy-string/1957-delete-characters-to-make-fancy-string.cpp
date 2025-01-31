class Solution {
public:
    string makeFancyString(string s) {
        string res = s.substr(0, 2);
        for (auto i = 2, r = 2; i < s.size(); i++) {
            auto should_skip = s[i] == s[i-1] && s[i-1] == s[i-2];
            if (!should_skip) res.push_back(s[i]);
        }
        return res;
    }
};