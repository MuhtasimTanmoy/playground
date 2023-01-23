class Solution {
    int mod = 1e9 + 7;
public:
    int numPrimeArrangements(int n, int primeCount = 0, long long res = 1) {
        vector<int> prime(n + 1, true);
        prime[0] = false; prime[1] = false;
        for (auto i = 2; i * i <= n; i++)
            if (prime[i])
                for (auto factor = 2; i * factor <= n; factor++) prime[i * factor] = false;
        for (auto val: prime) if (val) primeCount++;
        for (auto i = 1; i <= primeCount; i++) res = (res * i) % mod;
        for (auto i = 1; i <= n - primeCount; i++) res = (res * i) % mod;
        return res;
    }
};