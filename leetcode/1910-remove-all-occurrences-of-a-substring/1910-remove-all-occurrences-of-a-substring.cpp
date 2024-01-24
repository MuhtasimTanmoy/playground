class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        for (auto c: s) {
            res += c;
            if (res.size() >= part.size()) {
                auto last = res.size() - part.size();
                if (res.substr(last) == part) {
                    res = res.substr(0, last);
                }
            }
        }
        return res;
    }
};