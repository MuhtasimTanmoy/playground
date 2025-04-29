// class Solution {
// public:
//     int idealArrays(int n, int maxValue) {
        
//         function<int(int, int)> go = [&](auto l, auto now) {
//             if (l == 0) return now <= maxValue ? 1: 0;
//             if (now > maxValue) return 0;
            
//             int res = 0;
//             for (auto i = now, mul = 1; i <= maxValue; i = i * mul , mul++) {
//                 res = res + go(l - 1, i);
//             }

//             return res;
//         };

//         return go(n, 1);


//     }
// };


// https://leetcode.com/problems/count-the-number-of-ideal-arrays/solutions/6675673/dp-combinatorics-with-images-example-walkthrough-c-python-java/?envType=daily-question&envId=2025-04-22

const int mod = 1e9 + 7;
int factMemo[100000] = {};
int dp[100000][15];
using ll = long long;
class Solution {
public:
ll power(ll a, ll b, ll m = mod) {ll res = 1;while (b > 0) {if (b & 1)res = (res * a) % m;a = (a * a) % m;b = b >> 1;}return res;}
    ll fact(ll n) {
        if (n == 0) return 1;
        if (factMemo[n]) return factMemo[n];
        factMemo[n] = (n * fact(n - 1)) % mod;
        return factMemo[n];
    }
    ll mod_inv(ll a, ll b) {
        return (((fact(a) * power(fact(b), mod - 2)) % mod) * power(fact(a - b), mod - 2)) % mod;
    }

    int idealArrays(int n, int maxi) {
        for (int i = 1; i <= maxi; i++)
            for (int j = 1; j <= min(n, 14); j++)
                dp[i][j] = 0;
        for (int i = 1; i <= maxi; i++) {
            dp[i][1] = 1;
            for (int j = 2; j * i <= maxi; j++)
                for (int k = 1; k < min(n, 14); k++)
                    dp[i*j][k+1] += dp[i][k];
        }
        ll res = 0;
        for (int i = 1; i <= maxi; i++)
            for (int j = 1; j <= min(n, 14); j++)
                res = (res + mod_inv(n - 1, n - j) * dp[i][j]) % mod;
        return res;
    } 
};