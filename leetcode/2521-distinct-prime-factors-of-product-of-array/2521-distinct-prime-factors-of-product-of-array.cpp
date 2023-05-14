class Solution {
    int ps[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes;
        for (int n : nums) {
            for (int p : ps)
                if (n % p == 0) {
                    primes.insert(p);
                    while (n % p == 0) n /= p;
                }
            if (n != 1) primes.insert(n);
        }
        return primes.size();
    }
};