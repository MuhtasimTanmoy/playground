/*
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<string> bag;
        auto gen_key = [](int a, int b) { return to_string(a) + "-" + to_string(b); };
        unordered_set<int> less(nums.begin(), nums.end());
        for (auto a: less)
            for (auto b: less) {
                 auto or_res = a | b, and_res = a & b;
                 auto count = __builtin_popcount(or_res) + __builtin_popcount(and_res);
                 if (count >= k) {
                    auto key = gen_key(a, b), rev = gen_key(a, b);
                    bag.insert(key);
                    bag.insert(rev);
                 }
             }
        return bag.size();
    }  
};
*/

// https://leetcode.com/problems/number-of-excellent-pairs/discuss/2324984/JavaC%2B%2BPython-Inclusion-Exclusion-Principle

class Solution {
public:
    long long countExcellentPairs(vector<int>& A, int k) {
        long long cnt[30] = {}, res = 0;
        for (int a : unordered_set<int>(begin(A), end(A)))
            ++cnt[__builtin_popcount(a)];
        for (int i = 1; i < 30; ++i)
            for (int j = 1; j < 30; ++j)
                if (i + j >= k)
                    res += cnt[i] * cnt[j];
        return res;
    } 
};