class Solution {
public:
    string removeStars(string s) {
        string stk;
        for (auto c: s) 
            if (c == '*') stk.pop_back(); else stk += c;
        return stk;
    }
};