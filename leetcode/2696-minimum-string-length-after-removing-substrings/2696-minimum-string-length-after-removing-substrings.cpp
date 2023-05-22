class Solution {
public:
    int minLength(string s) {
        string stk;
        for (int i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (stk.empty()) stk += c;
            else {
                auto is_match_found = (stk.back() == 'A' && c =='B') 
                                   || (stk.back() == 'C' && c =='D');
                if (is_match_found) stk.pop_back(); else stk += c; 
            }
        }
        return stk.size();
    }
};