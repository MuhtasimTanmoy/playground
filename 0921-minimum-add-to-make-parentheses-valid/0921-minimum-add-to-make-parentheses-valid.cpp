class Solution {
public:
    int minAddToMakeValid(string s, int res = 0, string stk = "") {
        for (auto c: s) 
            if (c == ')') { if (stk.empty()) res++; else stk.pop_back(); }
            else stk += c;
        return res + stk.size();
    }
};