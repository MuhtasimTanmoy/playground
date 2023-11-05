class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        
        auto check_if_invalid = [&]() -> pair<bool, char> {
            auto one = count(s.begin(), s.end(), '1'), zero = n - one;
            if (s.size() & 1) {
                if (abs(one - zero) > 1) return {true, ' '};
            } else if (one != zero) return {true, ' '};
            return {false, one == zero ? ' ' : one > zero ? '1': '0'};
        };
        auto [is_invalid, flag] = check_if_invalid();
        if (is_invalid) return -1;
        
        auto check = [&](auto token) {
            char look_for = token; int defaulter = 0;
            for (auto c: s) {
                if (c != look_for) defaulter++;
                look_for = look_for == '1' ? '0' : '1';
            }
            return defaulter;
        };
        
        if (flag == ' ') return min(check('1'), check('0')) / 2; 
        else return (check(flag) + 1) / 2 ; 
    }
};