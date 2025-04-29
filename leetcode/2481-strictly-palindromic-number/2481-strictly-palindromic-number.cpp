class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        auto get_base = [&](auto base) {
            long long res = 0;
            while (n) 
                res += n % base,
                n /= base,
                res *= 10;
            return res;
        };

        auto is_palin = [](int num) {
            auto str_num = to_string(num);
            int l = 0, r = str_num.size() - 1;
            while (l < r) 
                if (str_num[l++] != str_num[r--]) return false;
            return true;
        };

        for (auto i = 2; i < n - 1; i++) {
            auto now = get_base(i);
            if (is_palin(now) == false) return false; 
        }

        return true;
    }
};