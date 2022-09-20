class Solution {
    
    bool isDigitSumEven(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return !(sum&1);
    }
    
public:
    int countEven(int num) {
        return isDigitSumEven(num) ? num >> 1 : ( ( ( num + 1 ) >> 1 ) - 1);
    }
};