class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        auto rev = [](int n) {
            int rn = 0;
            for (; n; n /= 10) rn = rn * 10 + n % 10;
            return rn;
        };
        for (int n : nums) s.insert(rev(n));
        return s.size();
    }
};