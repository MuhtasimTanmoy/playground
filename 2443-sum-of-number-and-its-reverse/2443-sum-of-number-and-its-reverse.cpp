class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        auto rev = [](int n) {
            int rn = 0;
            for (;n; n /= 10) rn = rn * 10 + n % 10;
            return rn;
        };
        
        for (int i = num / 2; i <= num; i++) 
            if (i + rev(i) == num) return true;
        
        return false;
    }
};