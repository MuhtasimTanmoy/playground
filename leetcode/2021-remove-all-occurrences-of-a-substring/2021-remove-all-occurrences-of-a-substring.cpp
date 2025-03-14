class Solution {
    inline bool ends_with(std::string const & value, std::string const & ending) {
        if (ending.size() > value.size()) return false;
        return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
    }
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        for (auto c: s) {
            res += c;
            if (ends_with(res, part)) res = res.substr(0, res.size() - part.size());
        }
        return res;
    }
};