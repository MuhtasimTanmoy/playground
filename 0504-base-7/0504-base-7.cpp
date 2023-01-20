class Solution {
public:
    string convertToBase7(int num, string res = "") {
        if (num == 0) return "0";
        if (num < 0) return '-' + convertToBase7(-num);
        while (num > 0) {
            res += (num % 7) + '0';
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};