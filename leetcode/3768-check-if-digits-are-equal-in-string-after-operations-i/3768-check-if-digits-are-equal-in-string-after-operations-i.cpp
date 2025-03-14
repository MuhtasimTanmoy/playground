class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string now = "";
            for (auto i = 1; i < s.size(); i++) {
                auto sum = (s[i-1] - '0') + (s[i] - '0');
                sum %= 10;
                now += '0' + sum;
            }
            s = now;
        }
        return s.front() == s.back();
    }
};