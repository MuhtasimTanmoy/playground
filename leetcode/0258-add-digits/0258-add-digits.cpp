class Solution {
public:
    int addDigits(int num) {
        
        auto get_digit_sum = [](int n, int sum = 0) {
            while (n) sum += n % 10, n /= 10;
            return sum;
        };
        do num = get_digit_sum(num);
        while (num > 9 && num != 2);
        return num;
    }
};