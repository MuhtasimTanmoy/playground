class Solution {
public:
    int punishmentNumber(int n) {
        function<bool(string, int)> is_valid = [&](auto s, auto num) {
            if (s.empty() && !num) return true;
            if (num < 0) return false;
            for (int i = 1; i <= s.size(); i++) {
                auto l = s.substr(0, i), r = s.substr(i);
                auto found = is_valid(r, num - stoi(l));
                if (found) return true;
            }
            return false;
        };
        int res = 1;
        for (int i = 2; i <= n; i++) 
            if (is_valid(to_string(i * i), i)) 
                res += i * i;
        return res;
    }
};