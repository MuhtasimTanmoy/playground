class Solution {
public:
    string removeKdigits(string num, int k) {
        num += "0";
        string res = "";
        for (int i = 0; i < num.size(); i++) {
            while (res.size() && k && num[i] < res.back()) res.pop_back(), k--;
            if (res.empty() && num[i] == '0') continue;
            res += num[i];
        }
        if (res.size()) res.pop_back();
        return res.size() ? res: "0";
    }
};