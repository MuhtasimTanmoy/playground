class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = ""; int pending = 0;
        for (auto c: s) 
            if (c == '(') {
                if (pending++) res += c;
            } else {
                if (pending-- > 1) res += c;
            }
        return res; 
    }
};