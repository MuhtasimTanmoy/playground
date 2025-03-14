class Solution {
public:
    int maximumSum(vector<int>& N) {
        unordered_map<int, multiset<int>> tracker;
        auto get_sum = [](int n) {
            int sum = 0;
            while (n) sum += n % 10, n /= 10;
            return sum;
        };
        for (auto n: N) {
            auto sum = get_sum(n);
            tracker[sum].insert(n);
        }
        int res = -1;
        for (auto [key, nums]: tracker) 
            if (nums.size() > 1) {
                auto lastItr = prev(nums.end()), llastItr = prev(lastItr);
                res = max(*lastItr + *llastItr, res);
            }
        return res;
    }
};