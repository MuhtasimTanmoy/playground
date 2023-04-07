class Solution {
public: 
    int countAnagrams(string s) {
        const int mod = 1e9 + 7; 
        int n = s.size(); 
        vector<long> fact(n + 1, 1), ifact(n + 1, 1), inv(n + 1, 1); 
        for (int x = 1; x <= n; ++x) {
            if (x >= 2) inv[x] = mod - mod/x * inv[mod%x] % mod; 
            fact[x] = fact[x-1] * x % mod; 
            ifact[x] = ifact[x-1] * inv[x] % mod; 
        }
        long ans = 1; 
        istringstream iss(s); 
        string buff; 
        while (iss >> buff) {
            ans = ans * fact[buff.size()] % mod; 
            vector<int> freq(26); 
            for (auto& ch : buff) ++freq[ch-'a']; 
            for (auto& x : freq) ans = ans * ifact[x] % mod; 
        }
        return ans; 
    }
}; 