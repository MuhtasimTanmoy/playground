class Solution {
public:
    int countDigits(int num) {
        auto cache = num;
        int res = 0;
        while (num) {
            auto rem = num % 10;
            num /= 10;
            if (cache % rem == 0) res++;
        }
        return res;
    }
};