class Solution {
public:
    int addDigits(int num) {
        while (num > 9) {
            int now = 0;
            while (num) now += num % 10, num /= 10;
            num = now;
        }
        return num;
    }
};