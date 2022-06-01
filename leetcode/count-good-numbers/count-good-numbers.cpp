class Solution {
public:
    int MOD = 1e9+7;
    
    long long power(long long x, long long n) {
        if(n == 0) return 1;
        long long temp = power ( (x * x) % MOD, n >> 1);
        if ( n % 2 ) temp = ( temp * x ) % MOD;
        return temp % MOD;
    }
    
    int countGoodNumbers(long long n) {
        long long evens = ( n + 1 ) / 2, odds = n - evens;
        long long res = 1;
        res = ( res * power(5, evens) ) % MOD;
        res = ( res * power(4, odds) ) % MOD;
        return res;
    }
};