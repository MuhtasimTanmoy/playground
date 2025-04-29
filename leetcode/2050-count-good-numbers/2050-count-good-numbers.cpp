// class Solution {
//     const int MOD = 1e9 + 7;
// public:
//     int countGoodNumbers(long long n) {
//         long long res = 1;
//         res = ( res * (n / 2) * 5 ) % MOD;
//         res = ( res * (n / 2) * 4 ) % MOD;
//         if (n & 1) res = (res * 4) % MOD;
//         return res;
//     }
// };

class Solution {
public:
    int MOD = 1e9+7;
    
    long long power(long long x, long long n) {
        if (n == 0) return 1;
        long long temp = power ( (x * x) % MOD, n >> 1);
        if ( n % 2 ) temp = ( temp * x ) % MOD;
        return temp;
    }
    
    int countGoodNumbers(long long n) {
        long long evens = ( n + 1 ) / 2, odds = n - evens, res = 1;
        res = ( res * power(5, evens) ) % MOD;
        res = ( res * power(4, odds) ) % MOD;
        return res;
    }
};