/*
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                long long num = 1LL * nums[i] * nums[j];
                if (num % k == 0) res++;
            }
        return res;
    }
};

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int can_div = 0;
        auto comb = [](int a) {
            int res = 1;
            for (int i = 1; i < a; i++) res *= i;
            return res;
        };
        for (auto num: nums) can_div += (num % k == 0);
        int to_others = nums.size() - can_div,
             to_us = can_div > 1 ? comb(can_div): 0;
        return to_others * can_div + to_us;
    }
};

*/

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& nu: nums) mp[gcd(nu, k)]++;
        long long res = 0;
        for (auto& [a, c1]: mp) 
            for (auto& [b, c2]: mp) 
                if (a <= b && a * (long) b % k == 0) 
                    res += a < b ? (long) c1 * c2 : (long) c1 * (c1 - 1) / 2;
        return res;    
    }
};

