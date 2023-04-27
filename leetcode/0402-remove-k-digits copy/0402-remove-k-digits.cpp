class Solution {
public:
    string removeKdigits(string num, int k, string res = "") {
        for (auto c: num) {
            while (res.size() && res.back() > c && k) res.pop_back(), k--;
            if (res.size() || c != '0') res.push_back(c);
        }
        while (res.size() && k--) res.pop_back();
        return res.size() ? res: "0";
    }
};