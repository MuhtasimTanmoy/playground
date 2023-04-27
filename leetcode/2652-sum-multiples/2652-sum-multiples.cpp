class Solution {
public:
    int sumOfMultiples(int n, int res = 0) {
        auto check = [](int num) {
            if (num % 3 == 0) return true;
            if (num % 5 == 0) return true;
            if (num % 7 == 0) return true;
            return false;
        };
        for (int i = 1; i <= n; i++) 
            if ( check (i) )
                res += i;
        return res;
    }
};