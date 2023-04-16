class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (auto c: s) 
            if (c == '(') stk.push_back(')');
            else if (c == '{') stk.push_back('}');
            else if (c == '[') stk.push_back(']');
            else {
                if (stk.empty() || c != stk.back()) return false;
                stk.pop_back();
            }
        return stk.empty();
    }
};