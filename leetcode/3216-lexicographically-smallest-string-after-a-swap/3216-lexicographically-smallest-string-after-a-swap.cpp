class Solution {
public:
    string getSmallestString(string s) {
        for (auto i = 1; i < s.size(); i++) {
            auto r = s[i] - '0', l = s[i-1] - '0';
            auto is_ok = (l & 1) == (r & 1);
            if (is_ok && l > r) {
                swap(s[i], s[i-1]);
                return s;
            }
        }
        return s;
    }
};