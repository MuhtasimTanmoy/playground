class Solution {
public:
    int maximumSum(vector<int>& N) {
        unordered_map<int, vector<int>> tracker;
        auto sum = [](int n) {
            int sum = 0;
            while (n) sum += n % 10, n /= 10;
            return sum;
        };
        for (auto n: N) tracker[sum(n)].push_back(n);
        
        int res = -1;
        for (auto [_, vals]: tracker) {
            if (vals.size() == 1) continue;
            sort(vals.begin(), vals.end());
            res = max(res, vals.back() + vals[vals.size() - 2]);
        }
        return res;
    }
};