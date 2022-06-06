class Solution {

    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }
public:
    bool isThree(int n) {
        int s = sqrt(n);
        return s * s == n && isPrime(s);
    }
};