class Solution {
public:
    int addDigits(int num) {
        
        int addition = INT_MAX;
        
        while(addition > 9) {
            addition = 0;
            while(num) {
                addition += num % 10;
                num /= 10;
            }
            num = addition;
        }
        return addition;
    }
};