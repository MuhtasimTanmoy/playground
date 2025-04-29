class Solution {
public:
    long long numberOfPowerfulInt(long long start, 
                                  long long finish, int limit, string s) {
        string start_ = to_string(start-1), finish_ = to_string(finish);
        return calculate(finish_, s, limit)-calculate(start_, s, limit);
    }

    long long calculate(string num, string s, int limit){
        if (num.length()<s.length()) return 0;
        if (num.length()==s.length()) return num >= s ? 1 : 0;
        string s_ = num.substr(num.length() - s.length(), s.length());
        long long ans = 0, n = num.length() - s.length();
        for (int i = 0; i < n; i++) {
            if (limit < (num[i] - '0')) {
                ans += (long) pow(limit + 1, n - i);
                return ans;
            }
            ans += (long)(num[i] - '0') * (long) pow(limit + 1, n - 1 - i);
        }
        if (s_ >= s) ans++;
        return ans;
    }
};